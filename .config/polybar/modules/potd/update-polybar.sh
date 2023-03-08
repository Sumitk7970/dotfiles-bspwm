#!/bin/bash

LC_STATUS=$(cat ~/.config/polybar/modules/potd/lcstatus)
GFG_STATUS=$(cat ~/.config/polybar/modules/potd/gfgstatus)
HOOK=0

if [[ $LC_STATUS == "0" && $GFG_STATUS == "0" ]]; then
  HOOK=0
elif [[ $LC_STATUS == "1" && $GFG_STATUS == "0" ]]; then
  HOOK=1
elif [[ $LC_STATUS == "0" && $GFG_STATUS == "1" ]]; then
  HOOK=2
else 
  HOOK=3
fi

polybar-msg action potd hook $HOOK
