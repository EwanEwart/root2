#!/bin/bash

i=0 # no blanks between = sign

while [ $i -le 2 ] # blanks !
do
  echo Number: $i
  ((i++))
done

