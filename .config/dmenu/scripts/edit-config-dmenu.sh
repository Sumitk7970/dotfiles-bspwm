#!/bin/bash

source ~/.config/dmenu/config.sh

declare -A options
options["zsh"]="/home/sumit/.zshrc"
options["bspwm"]="/home/sumit/.config/bspwm/bspwmrc"
options["sxhkd"]="/home/sumit/.config/sxhkd/sxhkdrc"
options["polybar"]="/home/sumit/.config/polybar/modules.ini"

choice=$(for key in ${!options[@]}; do echo $key; done | $DMENU "Edit config" -fn 'JetBrainsMono Nerd Font:size=11')
if [[ -v "options[$choice]" ]]; then
  alacritty -e nvim ${options[$choice]}
fi
