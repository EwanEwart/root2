#!/bin/bash

if [[ $1 ]]
then
	ip_address=$1
else
	ip_address=ewan-TravelMate-5760
fi

# while [ true ]
while :
do
  if ping -c 1 $ip_address &> /dev/null
  then
    echo "Host $ip_address is online"
    # break
  fi
  sleep 5
done

