/**
 * 7/8/2016
 * Demo created by Yaw Agyepong
 * Copyright Liquid Analytics
 *
 * **/

var express = require('express');
var router = express.Router();
var request = require('request');

var tokenPresent = function (req) {
    return req.cookies !== undefined
        && req.cookies.access_token && req.cookies.access_token !== "";
};

var tokenInfoPresent = function (req) {
    return req.cookies !== undefined
        && req.cookies.community !== undefined
        && req.cookies.community !== ""
        && req.cookies.userId !== undefined
        && req.cookies.userId !== ""
        && req.cookies.authenticatedUserId !== undefined
        && req.cookies.authenticatedUserId !== "";
};

/***
 * We specify router middleware to handle checking for a token and retrieving token info.
 * Because no route was specified, the middleware will be run on every request.
 * **/

router.use(function (req, res, next) {
    if (req.query !== undefined && req.query.code !== undefined && req.query.code !== "") {
        console.log("Currently performing auth flow, skipping token check.");
        next();
    }
    else if (!tokenPresent(req)) {
        console.log("Token not found. Redirecting user for authentication");
        res.writeHead(302, {
            'Location': process.env.LDS_OAUTH_URL + "/authorize?redirect_uri=" + process.env.SITE_URL + "/code"
            + "&scope=" + (process.env.SCOPE || "")
            + "&client_id=" + process.env.CLIENT_ID
            + "&response_type=code"
        });
        res.end();
    } else {
        console.log("Token found.");
        next();
    }
}, function (req, res, next) {
    if (req.query !== undefined && req.query.code !== undefined && req.query.code !== "") {
        console.log("Currently performing auth flow, skipping token info retrieval.");
        next();
        return;
    }
    else if (tokenInfoPresent(req)) {
        console.log("Token info already cached");
        next();
        return;
    }

    console.log("Retrieving token info");
    request.post({
        url: process.env.LS_URL + '/ls/api/oauth2/tokenInfo',
        headers: {
            'Authorization': 'Bearer ' + req.cookies.access_token
        }
    }, function (error, postResponse, body) {

        if (postResponse && postResponse.statusCode === 200) {
            var response = JSON.parse(body);

            var expireDate = new Date();
            expireDate.setMonth(expireDate.getMonth() + 1);

            console.log("Saving token info");
            res.cookie("userId", response.userId, {expires: expireDate});
            res.cookie("authenticatedUserId", response.authenticatedUserId, {expires: expireDate});
            res.cookie("community", response.community, {expires: expireDate});

            next();
        }
        else {
            res.writeHead(401);
            res.end();
        }
    });
});

router.get('/', function (req, res) {
    res.render('index', {title: 'Movies Collection'});
});

router.get('/movies', function (req, res) {
    var movieQuery = "SELECT * FROM %COMMUNITY%_entity_Movie m order by m.name LIMIT 250".replace("%COMMUNITY%", req.cookies.community);
    console.log("Generated query: " + movieQuery);

    var headers = {
            "Authorization": "Bearer " + req.cookies.access_token,
            "Content-type": "application/x-www-form-urlencoded",
            "X-LiquidPlatform-community": req.cookies.community
        },
        postData = {
            "itemType": "Movie",
            "faultBlocks": false,
            "preserveEnvironmentsList": false,
            "query": movieQuery
        };

    request.post({
        url: process.env.LS_URL + "/ls/api/data/sqlQuery",
        headers: headers,
        form: postData
    }, function (error, postResponse, body) {
        var movies = JSON.parse(body);
        res.render('movies', {title: 'Movies', movies: movies});
    });
});

/**
 * Clear all caches and other stored information when logging out
 * */
router.get('/logout', function(req, res) {
    res.clearCookie("access_token");
    res.clearCookie("community");
    res.clearCookie("userId");
    res.clearCookie("authenticatedUserId");

    res.redirect("/");
});

/***
 * This route handles the redirect from the OAuth after the user is authenticated.
 * */
router.get('/code', function (req, res) {

    var postData = {
        "redirect_uri": process.env.SITE_URL + "/code",
        "grant_type": "authorization_code",
        "client_id": process.env.CLIENT_ID,
        "code": req.query.code
    };

    request.post({
        url: process.env.LS_URL + '/ls/api/oauth2/token',
        form: postData
    }, function (error, postResponse, body) {
        console.log("Authentication complete");

        var response = JSON.parse(body);

        if (response.access_token !== undefined && response.access_token !== "") {
            var expireDate = new Date();
            expireDate.setMonth(expireDate.getMonth() + 1);

            console.log("Saving token");
            res.cookie("access_token", response.access_token, {expires: expireDate});
            res.writeHead(302, {
                "Location": process.env.SITE_URL + "/"
            });
            res.end();
        }
        else {
            res.render('error', {
                message: response.error_description,
                error: response.error
            });
        }
    });
});

module.exports = router;
