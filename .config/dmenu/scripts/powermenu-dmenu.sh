#!/bin/bash

source ~/.config/dmenu/config.sh

declare -A options
options["Lock"]="/home/sumit/.bin/blur-lock"
options["Suspend"]="systemctl suspend"
options["Hibernate"]="systemctl hibernate"
options["Logout"]="bspc quit"
options["Reboot"]="systemctl reboot"
options["Shutdown"]="systemctl poweroff"

choice=$(for i in ${!options[@]}; do echo $i; done | $DMENU "⏻ " -fn 'JetBrainsMono nerd font:size=11')
if [[ -v "options[$choice]" ]]; then
	${options[$choice]}
fi
