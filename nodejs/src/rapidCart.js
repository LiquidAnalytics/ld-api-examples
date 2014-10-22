#!/usr/bin/env node

/**
 * Created by liquid on 5/15/14.
 *
 * This will currently only work with CSG. We will test it out
 * and turn it into a module.
 */

var request = require('request');
var uuid = require('node-uuid');
var sleep = require('sleep');
var fs = require("fs");

// Create a csv file to store stats for each cart
var createFile = function(filename){
    fs.open(filename,"w",0644,function(e,fd){
        if(e) throw e;
        fs.write(fd,"time,cartId,timeToSubmitMs,timeToPollMs,applicationTimeMs,totalTimeMs\n",0,'utf8',function(e){
            if(e) throw e;
            fs.closeSync(fd);
        })
    });
}

// Write data to csv file
var writeInFile = function(filename,data){
    fs.open(filename,"a",0644,function(e,fd){
        if(e) throw e;
        fs.write(fd,data);
    });

}

// Convert UTC to current time zone
var LocalTime = function(){
    var d, s = "";
    d = new Date();
    s += d.getFullYear()  + "-";

    // Get the month
    if (d.getMonth()  < 9){
        s += "0" + (d.getMonth() + 1) + "-";
    }
    else{
        s += (d.getMonth() + 1) + "-";
    }
    // Get the Date
    if (d.getDate() < 10){
        s += "0" + d.getDate() + "T";
    }
    else{
        s += d.getDate() + "T";
    }
    // Get time
    s += d.toLocaleTimeString() + ".";
    s += d.getMilliseconds() +"Z";
    return s;
}


var log = function (level, message) {
    //var ts = new Date(Date.now());
    //var tsStr = ts.toISOString();
    var time_now = LocalTime();
    console.log(time_now + "|" + level + "|" + message);

}

var runTest = function (host, community, username, password, count,filename) {
    console.log("*******************************************\n");
    console.log("Press ctrl+s to pause, any button to resume.\n");
    console.log("*******************************************\n");
    log("INFO", "Starting test");
    createFile(filename);
    request.post({ url: host + '/ls/api/oauth2/token',
            form: {'grant_type': 'password',
                "client_id": process.env.CLIENT_ID,
                "client_secret": process.env.CLIENT_SECRET,
                "username": username,
                "password": password,
                "scope": "community="+community}},
        function (error, postResponse, body) {
            var resp = JSON.parse(body);
            if (resp["error"] != null) {
                log("ERROR", "Couldn't authenticate " + body);
                process.exit(1);
            }
            var accessToken = resp['access_token'];
            var state = {
                txnAttempted: 0,
                txnSucceeded: 0,
                txnFailed: 0,
                polls: 0,
                totalApplicationTime: 0,
                totalSubmitTime: 0,
                totalPollTime: 0,
                totalTime: 0
            }
            prepareCart(host, accessToken, username, state, count,filename);
        });
}


var completeTest = function (state) {
    console.log(state);
    log("INFO", "Transactions attempted:"
        + state.txnAttempted
        + "\nTransactions succeeded:"
        + state.txnSucceeded
        + "\nTransactions failed:"
        + state.txnFailed
        + "\nAvg application time:" + (state.totalApplicationTime / state.txnSucceeded)
        + "\nAvg submit time:" + (state.totalSubmitTime / state.txnAttempted)
        + "\nAvg poll time:" + (state.totalPollTime / state.polls)
        + "\nAvg round trip time:" + (state.totalTime / state.txnSucceeded));

    // Wait to make sure all stats have been written in csv, then exit
    setTimeout(function () {
        process.exit(0);
    }, 10);

}


var prepareCart = function (host, accessToken, username, state, count,filename) {
    if (count == 0) {
        completeTest(state);
    }
    else {
        log("INFO", "Preparing the cart");
        request.post({
                url: host + '/ls/api/testing/randomItems',
                headers: {
                    'Authorization': 'Bearer ' + accessToken
                },
                form: {
                    "type": "Product",
                    "count": 10
                }
            },
            function (error, postResponse, body) {
                //console.log(body);
                var randomProducts = JSON.parse(body);
                request.post({
                        url: host + '/ls/api/testing/randomItems',
                        headers: {
                            'Authorization': 'Bearer ' + accessToken
                        },
                        form: {
                            "type": "Account",
                            "count": 1
                        }
                    },
                    function (error, postResponse, body) {
                        //console.log(body);
                        var randomAccount = JSON.parse(body)[0];
                        //Now we can create a cart
                        var cart = {}
                        cart["headers"] = {
                            category: "work", type: "Cart",
                            clientId: "TEST-" + uuid.v1(),
                            revisionId: uuid.v1(),
                            action: "Create"
                        }
                        cart["data"] = {
                            cartId: cart.headers.clientId,
                            accountId: randomAccount["data"]["accountId"],
                            name: cart.headers.clientId,
                            processStatus: "/Workflow/processStatus[Verify]",
                            processType: "/Workflow/cartType[Order]/processType[1]",
                            userId: username,
                            combineForInvoice: true,
                            lineItems: []
                        }
                        var lineItemId = 0;
                        randomProducts.forEach(function (product, index) {
                            if (product == null) {
                                return;
                            }
                            var productId = product.data.productId;
                            var productDescription = product.data.productDescription;
                            var uom = product.data.baseUOM;
                            lineItem = {
                                lineItemId: lineItemId,
                                productId: productId,
                                uom: uom,
                                productDescription: productDescription,
                                requestedQuantity: 10
                            }
                            cart.data.lineItems.push(lineItem);
                            lineItemId = lineItemId + 1;
                        });

                        submitCart(host, accessToken, cart, username, state, count, filename);


                    })
            });
    }
}

var submitCart = function (host, accessToken, cart, username, state, count,filename) {
    state.txnAttempted = state.txnAttempted + 1;
    log("INFO", "Submitting a cart " + count);
    var start = Date.now();
    var time_now = LocalTime();
    var cartNo = time_now + "," + count + ",";
    writeInFile(filename,cartNo);
        request.post({
            url: host + '/ls/api/transactions/submit',
            headers: {
                'Authorization': 'Bearer ' + accessToken,
                'content-type': 'application/json'
            },
            body: JSON.stringify([ cart ])
        },
        function (error, postResponse, body) {
            var end = Date.now();
            state.totalSubmitTime = state.totalSubmitTime + (end - start);
            var submitTime = (end -start) + ",";
            writeInFile(filename,submitTime);
            var deliveryConfirmations = JSON.parse(body);
            poll(host, accessToken, deliveryConfirmations, username, state, count, 60, start,filename);
        })


}

var poll = function (host, accessToken, deliveryConfirmations, username, state, count, pollCount, start,filename) {
    if (pollCount == 0) {
        log("FAIL", "Polling has expired, and we have yet to get our transaction back");
        count = count - 1;
        prepareCart(host, accessToken, username, state, count, start,filename);
    }
    else {
        log("INFO", "Polling for transaction " + pollCount);
        if (!deliveryConfirmations[0].accepted) {
            log("FAIL", "Failed to submit a cart: " + deliveryConfirmations[0].deliveryReason);
            state.txnAttempted = state.txnFailed + 1;
            count = count - 1;
            prepareCart(host, accessToken, username, state, count, start,filename);
        }
        else {
            state.polls = state.polls + 1;
            var pollStart = Date.now();
            request.post({
                    url: host + '/ls/api/transactions/poll',
                    headers: {
                        'Authorization': 'Bearer ' + accessToken,
                        'content-type': 'application/json'
                    },
                    body: JSON.stringify(deliveryConfirmations)
                },
                function (error, postResponse, body) {
                    var end = Date.now();
                    state.totalPollTime = state.totalPollTime + (end - pollStart);
                    var pollTime = (end - pollStart) + ",";
                    writeInFile(filename,pollTime);
                    count = count - 1;
                    var items = JSON.parse(body);
                    if (items.length == 0) {
                        pollCount = pollCount - 1;
                        sleep.sleep(1);
                        poll(host, accessToken, deliveryConfirmations, username, state, count, pollCount,filename);
                    }
                    else {
                        var item=items[0].item;
                        var applicationTime = JSON.parse(item.headers.applicationTime);
                        state.totalApplicationTime = state.totalApplicationTime + applicationTime;
                        state.txnSucceeded = state.txnSucceeded + 1;
                        state.totalTime = state.totalTime + (end- start);
                        var app_total_time = applicationTime + "," + (end-start) + "\n";
                        writeInFile(filename,app_total_time);
                        console.log("----------------------------------------");
                        prepareCart(host, accessToken, username, state, count,filename);
                    }

                })
        }
    }


}



// Pass in arguments
var PassInCommand = function(args){
    runTest(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
}

//eg. runTest("https://lddev.charmer-sunbelt.com", "CSG_Dev","RPETITTE", "mobileapp", 5, "record.csv");
PassInCommand(process.argv.slice(2));


process.stdin.resume();
process.on('SIGINT', function() {
    var pid = process.pid;
    console.log("Got a SIGINT. Process exit. " + "pid " + pid);
    process._kill(pid,9);
    //process.exit(0);
});

