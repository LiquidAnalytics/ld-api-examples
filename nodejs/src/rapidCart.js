#! /usr/bin/nodejs
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
        fs.write(fd,"time,deviceId,userId,cartId,timeToSubmitMs,timeToPollMs,receiptType,receiptMessage,processStatus,applicationTimeMs,totalTimeMs\n",0,'utf8',function(e){
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

var pauseTime;
var globalFilename;

var runTest = function (host, community, username, password, count,filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems) {
    console.log("*******************************************\n");
    console.log("Press ctrl+s to pause, any button to resume.\n");
    console.log("*******************************************\n");
    log("INFO", "Starting test for "+username+" with host"+host);
    createFile(filename);
    globalFilename = filename;
    var req = request.post({ url: host + '/ls/api/oauth2/token',
            form: {'grant_type': 'password',
                "client_id": "LiquidDecisions",
                "client_secret": process.env.CLIENT_SECRET,
                "username": username,
                "password": password,
                "scope": "community="+community}},
        function (error, postResponse, body) {
	log("INFO", "In token result"+body+error+postResponse);
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
            log("INFO", "end test"+accessToken);
            pauseTime = (lengthOfDay/count)*60;
            prepareCart(host, accessToken, username, state, count,filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems);
        });

/*	var data = '';
	req.on('data', function(chunk){
		  data += chunk;
	});
	 req.on('end', function(){
        var obj = JSON.parse(data);
        log("INFO", "In token result"+obj);
    });	*/
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


var prepareCart = function (host, accessToken, username, state, count,filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems) {
    if (count == 0) {
        completeTest(state);
    }
    else {

        log("INFO", "Preparing the cart Initiated");
        sleep.sleep(pauseTime*(Math.random() < 0.5 ? -1.15 : 1.15));
        log("INFO", "Preparing the cart Started");
        filename = globalFilename+count+".csv";
        writeInFile(filename,LocalTime()+",");
        numberofproducts = numOfLineItems;
        request.post({
                url: host + '/ls/api/testing/randomItems',
                headers: {
                    'Authorization': 'Bearer ' + accessToken
                },
                form: {
                    "type": "Product",
                    "count": numberofproducts
                }
            },
            function (error, postResponse, body) {
                //console.log(body);
                log("INFO", "randomItems products response");
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
                        writeInFile(filename,",");
                        writeInFile(filename,username+",");
                        writeInFile(filename,cart.headers.clientId+",");
                        cart["data"] = {
                            cartId: cart.headers.clientId,
                            accountId: randomAccount["data"]["accountId"],
                            name: cart.headers.clientId,
                            processStatus: "/Workflow/processStatus[Submit]",
                            processType: "/Workflow/cartType[Order]/processType[ZBTO]",
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
                            var uom = product.data.baseUom;
                            var requestedUnitPrice = 0;
                            if(isGetPrice=="Y"){
                                var startPriceTime = Date.now();
                                var priceFilename = "price_"+globalFilename+".csv";
                                //writeInFile(priceFilename,LocalTime()+","+","+username+","+productId+","+randomAccount["data"]["accountId"]+",");
                                request.post({
                                        url: host + '/ls/api/data/query?function=GetPricesForAccountProduct&responseFormat=TableData&maxResults=10',
                                        headers: {
                                            'Authorization': 'Bearer ' + accessToken
                                        },
                                        json: [{
                                            "accountId": randomAccount["data"]["accountId"],
                                            "productId": productId,
                                            "userId":"DON.LOONEY@GLAZERS.COM",
                                            "processType":"ZBTO",
                                            "quantity":10,
                                            "uom":uom
                                        }]
                                    },
                                    function (error, postResponse, body) {

					                    if('tableData' in body[0]){
                                            //writeInFile(priceFilename,body[0]["tableData"].length+","+Date.now()-startPriceTime+","+body[0]["status"]);
 	                                       var requestedUnit = body[0]["tableData"][0];
        	                                if(requestedUnit["minimumQuantityUom"]=="CS")
                	                        {
                        	                    requestedUnitPrice = requestedUnit["netPrice"];
                                	        }else{
                                        	    requestedUnitPrice = requestedUnit["eachPrice"];
                                       		 }
					                    }else{
                                            //writeInFile(priceFilename,0+","+","+Date.now()-startPriceTime+","+body[0]["status"]);
                                        }
                                        lineItem = {
                                            lineItemId: lineItemId,
                                            productId: productId,
                                            uom: uom,
                                            productDescription: productDescription,
                                            requestedQuantity: 1,
                                            requestedUnitPrice:requestedUnitPrice

                                        }

                                        cart.data.lineItems.push(lineItem);

                                        lineItemId = lineItemId + 1;

                                        if(lineItemId==numberofproducts && isSubmitCart=="Y")
                                            submitCart(host, accessToken, cart, username, state, count, filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems);
                                    });
                            }else{

                                lineItem = {
                                    lineItemId: lineItemId,
                                    productId: productId,
                                    uom: uom,
                                    productDescription: productDescription,
                                    requestedQuantity: 1,
                                    requestedUnitPrice:requestedUnitPrice

                                }

                                cart.data.lineItems.push(lineItem);

                                lineItemId = lineItemId + 1;
                                if(lineItemId==numberofproducts && isSubmitCart=="Y")
                                    submitCart(host, accessToken, cart, username, state, count, filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems);

                            }

                        });
                    })
            });
    }
}

var submitCart = function (host, accessToken, cart, username, state, count,filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems) {
    state.txnAttempted = state.txnAttempted + 1;
    log("INFO", "Submitting a cart " + count);
    var start = Date.now();
    var time_now = LocalTime();
    var cartNo = time_now + "," + count + ",";

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
            poll(host, accessToken, deliveryConfirmations, username, state, count, 60, start,filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems);
        })


}

var poll = function (host, accessToken, deliveryConfirmations, username, state, count, pollCount, start,filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems) {
    if (pollCount == 0) {
        log("FAIL", "Polling has expired, and we have yet to get our transaction back");
        count = count - 1;
        prepareCart(host, accessToken, username, state, count, start,filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems);
    }
    else {
        log("INFO", "Polling for transaction " + pollCount);
        if (!deliveryConfirmations[0].accepted) {
            log("FAIL", "Failed to submit a cart: " + deliveryConfirmations[0].deliveryReason);
            state.txnAttempted = state.txnFailed + 1;
            count = count - 1;
            prepareCart(host, accessToken, username, state, count, start,filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems);
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

                    count = count - 1;
                    var items = [];
                    if(body!="")
                    {
                        items = JSON.parse(body)
                    }
                    if (items.length == 0) {
                        pollCount = pollCount - 1;
                        sleep.sleep(1);
                        poll(host, accessToken, deliveryConfirmations, username, state, count, pollCount,filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems);
                    }
                    else {
                        var item=items[0].item;
                        var applicationTime = JSON.parse(item.headers.applicationTime);
                        state.totalApplicationTime = state.totalApplicationTime + applicationTime;
                        state.txnSucceeded = state.txnSucceeded + 1;
                        state.totalTime = state.totalTime + (end- start);
                        writeInFile(filename,pollTime);
                        writeInFile(filename,item.headers.receiptType+",");
                        var receiptMessage = item.headers.receiptMessage.replace(/\n/g, '-');
                        writeInFile(filename,receiptMessage+",");
                        writeInFile(filename,item.headers.state+",");
                        var app_total_time = applicationTime + "," + (end-start) + "\n";
                        writeInFile(filename,app_total_time);
                        console.log("----------------------------------------");
                        prepareCart(host, accessToken, username, state, count,filename, isSubmitCart, isGetPrice, lengthOfDay, numOfLineItems);
                    }

                })
        }
    }


}



// Pass in arguments
var PassInCommand = function(args){
    runTest(args[0],args[1],args[2],args[3],args[4],args[5],args[6],args[7],args[8]);
}

PassInCommand(process.argv.slice(2));

process.stdin.resume();
process.on('SIGINT', function() {
    var pid = process.pid;
    console.log("Got a SIGINT. Process exit. " + "pid " + pid);
    process._kill(pid,9);
    //process.exit(0);
});

