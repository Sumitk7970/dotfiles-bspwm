#!/bin/bash

# move into notes dir and open nvim in floating mode 

bspc rule -a \* -o state=floating sticky=on layer=above rectangle=720x360+1180+26 && alacritty -e nvim ~/notes/study-later
# bspc rule -a \* -o state=floating sticky=on layer=above rectangle=720x360+600+26 && alacritty
