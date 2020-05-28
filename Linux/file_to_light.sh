#!/bin/bash

chrbin() {
        echo $(printf \\$(echo "ibase=2; obase=8; $1" | bc))
}

ordbin() {
  a=$(printf '%d' "'$1")
  echo "obase=2; $a" | bc
}

ascii2bin() {
    echo -n $* | while IFS= read -r -n1 char
    do
        ordbin $char | tr -d '\n'
        #echo -n " "
    done
}

###################################################################
# read the file
value=$(<test.txt)
###################################################################
binchain=$(ascii2bin "${value}")

printf "the chain : \n${binchain}"

for (( i=0; i<${#binchain}; i++ )); do
  printf "${binchain:$i:1}\n"
  if [ "${binchain:$i:1}" -eq "1" ]
  then
    xrandr --output $(xrandr|grep ' connected '|awk '{print $1}' ) --brightness 2
  else
    xrandr --output $(xrandr|grep ' connected '|awk '{print $1}' ) --brightness 0.5
  fi
  sleep 1
done

xrandr --output $(xrandr|grep ' connected '|awk '{print $1}' ) --brightness 10