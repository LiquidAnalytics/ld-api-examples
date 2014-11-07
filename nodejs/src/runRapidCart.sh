#!/bin/bash
INPUT=$1
CART_NUMBER=$2
OUTPUT=$3
HOST=$4
COMMUNITY=$5
OLDIFS=$IFS
COUNT=1
FILENAME="record"
FILETYPE=".csv"
IFS=,
[ ! -f $INPUT ] && { echo "$INPUT file not found"; exit 99; }
while read username password
do
	./rapidCart.js $HOST $COMMUNITY $username $password $CART_NUMBER $FILENAME$COUNT$FILETYPE &
	COUNT=$((COUNT+1))
done < $INPUT
IFS=$OLDIFS
wait
REPLACE="*"
cat $FILENAME$REPLACE$FILETYPE > $OUTPUT
rm $FILENAME$REPLACE$FILETYPE
