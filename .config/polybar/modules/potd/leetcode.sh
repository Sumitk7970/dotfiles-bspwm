#!/bin/bash

FILE=~/.config/polybar/modules/potd/lcstatus

if [[ "$1" == "reset" ]]; then
  echo 0 > $FILE
  ~/.config/polybar/modules/potd/update-polybar.sh
  exit 0
fi
  
# if file does not exist then write 1 so that it will 
# eventually become 0
if [[ ! -f $FILE ]]; then
  echo 1 > $FILE
fi

if [[ $(cat $FILE) == "0" ]]; then
  echo 1 > $FILE
else
  echo 0 > $FILE
fi 

~/.config/polybar/modules/potd/update-polybar.sh
