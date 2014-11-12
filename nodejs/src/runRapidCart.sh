#!/bin/bash
INPUT=$1
CART_NUMBER=$2
OUTPUT=$3
HOST=$4
COMMUNITY=$5
ISSUBMITCART=$6
ISGETPRICE=$7
NUMDEVICES=$8
LENGTHOFDAY=$9
NUMBEROFDAYS=$[10]
NUMBEROFLINEITEM=$[11]
OLDIFS=$IFS
COUNT=0
FILENAME="record"
FILETYPE=".csv"
IFS=,
[ ! -f $INPUT ] && { echo "$INPUT file not found"; exit 99; }
echo $NUMBEROFLINEITEM
#echo $NUMBEROFDAYS
while [ $COUNT -lt $NUMDEVICES ]
do
    while read username password
    do
        ./rapidCart.js $HOST $COMMUNITY $username $password $CART_NUMBER $FILENAME$COUNT$FILETYPE $ISSUBMITCART $ISGETPRICE $LENGTHOFDAY $NUMBEROFLINEITEM $NUMDEVICES &
        COUNT=$((COUNT+1))
    done < $INPUT
done
IFS=$OLDIFS
wait
REPLACE="*"
rm $OUTPUT
echo "time,deviceId,userId,cartId,timeToSubmitMs,timeToPollMs,receiptType,receiptMessage,processStatus,applicationTimeMs,totalTimeMs\n" >> $OUTPUT
cat $FILENAME$REPLACE$FILETYPE >> $OUTPUT
rm $FILENAME$REPLACE$FILETYPE
