#!/bin/bash
USERLIST=$1
COUNT=$2
HOST=$3
COMMUNITY=$4
OLDIFS=$IFS
FILENAME="record"
FILETYPE=".csv"
IFS=,
START=$(date +%s)
[ ! -f $USERLIST ] && { echo "$USERLIST file not found"; exit 99; }

while read username password
do
    nodejs ./dayInLife.js ${HOST} ${COMMUNITY} $username $password
done < $USERLIST

IFS=$OLDIFS
END=$(date +%s)
DIFF=$(( $END - $START ))
echo "It took $DIFF seconds"