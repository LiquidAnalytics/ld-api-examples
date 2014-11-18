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
var log4js = require("log4js");

var timeout = 120000;


// Convert UTC to current time zone
var LocalTime = function () {
    var d, s = "";
    d = new Date();
    s += d.getFullYear() + "-";

    // Get the month
    if (d.getMonth() < 9) {
        s += "0" + (d.getMonth() + 1) + "-";
    }
    else {
        s += (d.getMonth() + 1) + "-";
    }
    // Get the Date
    if (d.getDate() < 10) {
        s += "0" + d.getDate() + "T";
    }
    else {
        s += d.getDate() + "T";
    }
    // Get time
    s += d.toLocaleTimeString() + ".";
    s += d.getMilliseconds() + "Z";
    return s;
};

var start=null;

var runTest = function (host, community, username, password) {
    start=new Date();
    var deviceId = "TEST-" + uuid.v1();
    var hardwareName=username+"'s Test harness";
    var hardwareId="TEST-"+uuid.v1();
   // log4js.clearAppenders();
    log4js.loadAppender('file');
//log4js.addAppender(log4js.appenders.console());

    log4js.addAppender(log4js.appenders.file('logs/' + username + "-" + deviceId + ".log"), username);
    var logger = log4js.getLogger(username);
    logger.setLevel('INFO');
    logger.info("Getting token...");
    request.post({ url: host + '/ls/api/oauth2/token',
            timeout: timeout,
            form: {'grant_type': 'password',
                "client_id": "LiquidDecisions",
                "client_secret": process.env.CLIENT_SECRET,
                "username": username,
                "password": password,
                "scope": "deviceId=" + deviceId + " hardwareId=" + hardwareId + " hardwareName=" + hardwareName}},
        function (error, postResponse, body) {
            var resp = JSON.parse(body);
            if (resp["error"] != null) {
                logger.error("Couldn't authenticate : " + resp["error_description"]);
                process.exit(1);
            }
            var accessToken = resp['access_token'];
            getRootConfig(host, community, accessToken, hardwareName, hardwareId, deviceId, logger)
        });
};

var getRootConfig = function (host, community, accessToken, hardwareName, hardwareId, deviceId, logger) {
    logger.info("Getting root config");
    request.post({
            url: host + '/ls/api/sync/3.0/getConfiguration',
            timeout: timeout,
            headers: {
                'Authorization': 'Bearer ' + accessToken
            },
            form: {
                "community": "root"
            }
        },
        function (error, postResponse, body) {
            getTokenInfo(host, community, accessToken, hardwareName, hardwareId, deviceId, logger)
        })
};

var getTokenInfo = function (host, community, accessToken, hardwareName, hardwareId, deviceId, logger) {
    logger.info("Getting token info...");
    request.post({
            url: host + '/ls/api/oauth2/tokenInfo',
            timeout: timeout,
            headers: {
                'Authorization': 'Bearer ' + accessToken
            },
            form: {

            }
        },
        function (error, postResponse, body) {
            if (error != null) {
                logger.error("Error getting token info");
                process.exit(1);
            }
            setHardwareProperties(host, community, accessToken, hardwareName, hardwareId, deviceId, logger)
        })
};

var setHardwareProperties = function (host, community, accessToken, hardwareName, hardwareId, deviceId, logger) {
    logger.info("Setting hardware properties");
    request.post({
            url: host + '/ls/api/oauth2/setProperties',
            timeout: timeout,
            headers: {
                'Authorization': 'Bearer ' + accessToken
            },
            form: {
                "community": community,
                "hardwareName": hardwareName,
                "hardwareId": hardwareId,
                "applicationName": "Test harness",
                "clientBuild": "1.0"
            }
        },
        function (error, postResponse, body) {
            if (error != null) {
                logger.error("Error setting hardware properties - "+error);
                process.exit(1);
            }
            setupManifest(host, community, accessToken, logger);
        })
};

var setupManifest = function (host, community, accessToken, logger) {
    logger.info("Setting up manifest...");
    request.post({
            url: host + '/ls/api/sync/3.0/setupManifest',
            timeout: timeout,
            headers: {
                'Authorization': 'Bearer ' + accessToken
            },
            form: {
                //Nothing
            }
        },
        function (error, postResponse, body) {
            if (error != null) {
                logger.error("Error setting up manifest "+error);
                process.exit(1);
            }
            pollManifestStatus(host, community, accessToken, logger)
        })
};

var pollManifestStatus = function (host, community, accessToken, logger) {
    logger.info("Polling for manifest setup status...");
    request.post({
            url: host + '/ls/api/sync/3.0/manifestStatus',
            timeout: timeout,
            headers: {
                'Authorization': 'Bearer ' + accessToken
            },
            form: {
                //Nothing
            }
        },
        function (error, postResponse, body) {
            if (error != null) {
                logger.error("Error polling manifest:"+error);
                process.exit(1);
            }
            try{
                var status = JSON.parse(body);

                if (status.state == "Registered") {
                    logger.info("Manifest is ready!!!" + body);

                    sync(host, accessToken, community, status.itemCount, 0, logger);
                }
                else {
                    logger.info("Not yet registered, waiting for manifest to be setup");
                    sleep.sleep(30);
                    pollManifestStatus(host, community, accessToken, logger);
                }
            }
            catch(err)
            {
                logger.error("Couldn't parse "+body);
                sleep.sleep(5);
                pollManifestStatus(host, community, accessToken, logger);
            }


        })
};

var sync = function (host, accessToken, community, itemCount, count, logger) {
    logger.info(Math.round(100 * count / itemCount) + "% Syncing... Received " + count + " items so far");
    request.post({
            url: host + '/ls/api/sync/3.0/getItems',
            timeout: timeout,
            headers: {
                'Authorization': 'Bearer ' + accessToken
            },
            form: {
                "clientBuild": "1.0",
                "requestId": uuid.v1(),
                "count": 5000,
                "community": community,
                "weight": 500000
            }
        },
        function (error, postResponse, body) {
            logger.info("Parsing getItems body");
            var items=[];
            try
            {
                items = JSON.parse(body);
            }
            catch(parseError)
            {
                logger.error(parseError);
                sync(host, accessToken, community, itemCount, count + items.length, logger);
            }
            logger.info("Received :" + items.length);
            if (items.length > 5000) {
                //logger.warn("> 5000", body);
            }
            if (items.length > 0) {
                var manifestRecordList = []

            items.forEach(function (item, index) {

                if('schema' in item)
                {
                    manifestRecord = {
                        category: item.schema.category,
                        type: item.schema.type,
                        id: "",
                        revisionId: ""
                    }
                }else if('headers' in item){
                    manifestRecord = {
                        category:  item.headers.category,
                        type:   item.headers.type,
                        id: item.headers.id,
                        revisionId: item.headers.revisionId
                    }
                }else if('item' in item && 'headers' in item.item){
                    manifestRecord = {
                        category:  item.item.headers.category,
                        type:   item.item.headers.type,
                        id: item.item.headers.id,
                        revisionId: item.item.headers.revisionId
                    }
                }
                manifestRecordList.push(manifestRecord);
            });
                request.post({
                        url: host + '/ls/api/sync/3.0/verifyChanges',
                        timeout: timeout,
                        headers: {
                            'Authorization': 'Bearer ' + accessToken,
                            'content-type': 'application/json'
                        },
                        body: JSON.stringify( manifestRecordList )
                    },
                    function (error, postResponse, body) {
                        logger.info("Parsing Verify changes body");
                        try
                        {
                            var state = JSON.parse(body);
                            logger.info("Verify State"+body);
                        }
                        catch(parseError)
                        {
                            logger.error(parseError);

                        }
                    })
                logger.info("Pretending to process items...");
               sleep.sleep(10);
                sync(host, accessToken, community, itemCount, count + items.length, logger);
            }
            else {
                var end=new Date();
                var totalTimeMins=(end.getTime()-start.getTime())/1000/60;

                if(totalTimeMins<15)
                {
                    logger.info("Total time is "+totalTimeMins+" Re-sync started");
                    sleep.sleep(60);
                    sync(host, accessToken, community, itemCount, count + items.length, logger);

                }else{
                    logger.info("Registration completed in "+totalTimeMins+" mins");
                    sleep.sleep(5);
                    process.exit(0)
                }
                /**
                 * If totalTimeMins<=15 mins {
                 * 	sleep(60 seconds)
                 * 	 sync(host, accessToken, community, itemCount, count + items.length, logger);
                 * }
                 * else
                 * {
                 * Do what it does today
                 * }
                 */
               

            }


        })


}

// Pass in arguments
var PassInCommand = function (args) {
    //for (i=0;i<10;i++) {
    runTest(args[0], args[1], args[2], args[3], args[4], args[5], args[6]);
    //}
};

//PassInCommand(process.argv.slice(2));

runTest("https://ldcloud-dev.liquidanalytics.com", "GLAZERS","DAVID.BON@GLAZERS.COM", "Mobileapp1");

process.stdin.resume();
process.on('SIGINT', function () {
    var pid = process.pid;
    console.log("Got a SIGINT. Process exit. " + "pid " + pid);
    //process._kill(pid, 9);
    process.exit(0);
});

