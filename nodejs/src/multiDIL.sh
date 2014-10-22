#!/bin/bash
USERLIST=$1
COUNT=$2
HOST=$3
COMMUNITY=$4

for i in `seq 1 ${COUNT}`
do
    sh ./runDayInLife.sh ${USERLIST} ${COUNT} ${HOST} ${COMMUNITY} &
    sleep 5
done
wait
