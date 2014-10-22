Liquid Decisions Test Harness README 1st
===========

This tool can be used for the following tests:

* Register as a single user and confirm registration works
* Register as multiple concurrent devices and test the load

Pre-Requisites
------
* You need to have Node.js installed and accessible in the PATH as "node" command.
* The tool is designed to run on Linux or on a Mac OS X
* To run as multiple devices you need a hefty machine with sufficient network bandwidth

How to run
-------
All commands are run in the "src" directory:

### Register as a single user


nodejs ./dayInLife.js *host* *community* *username* *password*

For example:

nodejs ./dayInLife.js https://ldcloud-dev.liquidanalytics.com *MyCommunity* *MyUsername* *password*

### Register using a user list

This requires a CSV with usernames and passwords like this:

*username*,*password*

To run it:

./runDayInLife.sh *filename* 1 *host* *community*

(1 here is unused at the moment, but please pass it anyway for now)

For example:

./runDayInLife.sh 30Users.csv 1 https://ldcloud-dev.liquidanalytics.com  *MyCommunity*

### Register as Multiple Devices

Use multiDIL.sh script:

./multiDIL.sh *userlist* *concurrentRegistrations* *host* *community*

For example:

nohup ./multiDIL.sh KnownThatWork.csv 15 https://ldcloud-dev.liquidanalytics.com *MyCommunity* > 15users.log & tail -f 15users.log

