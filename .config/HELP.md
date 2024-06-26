## Refresh mirror 
- Command to refresh mirrors 
```
sudo reflector --verbose --country 'India' -l 5 --sort rate --save /etc/pacman.d/mirrorlist
```

OR

- Automatically update mirrors 
```
sudo systemctl enable reflector.service reflector.timer
sudo systemctl start reflector.service reflector.timer
```

## For neovim config
Use astronvim

## For zsh
- oh-my-zsh for plugin management
- Powerlevel10k/starship for zsh prompt

## grub rescue 
1. find directory /boot/grub/
2. set root = (hdx,gpty)
3. set prefix = (hdx,gpty)/boot/grub
4. insmod normal 
5. normal

## backup dotfiles with git bare repository
1. Create a git bare repository 
```
mkdir dotfiles && cd dotfiles
git init --bare
```
2. Add this to .zshrc or .bashrc
```
alias dot="/usr/bin/git --git-dir=$HOME/dotfiles/ --work-tree=$HOME" 
```
3. Stop showing untracked file
```
dot config --local status.showUntrackedFiles no
```

## setup libinput gestures
1. Download libinput-gestures package from aur
2. copy the config from /etc/libinput-gestures.conf to ~/.config/libinput-gestures.conf
3. Add user to input group
```
sudo gpasswd -a $User input
newgrp input
```
3. Reboot

## w3m not working on bspwm
Use ueberzug method for previewing images

## configure fonts 
1. yay -S ttf-noto-fonts ttf-noto-fonts-extra ttf-noto-fonts-emoji ttf-jetbrains-mono-nerd 
2. Download SF-Pro font and paste it into /usr/share/fonts [Link](https://github.com/sahibjotsaggu/San-Francisco-Pro-Fonts.git)
3. Change system font to SF Pro Display Medium size 11.

## for java awt applications not working properly
- Add this to /etc/profile
```
export _JAVA_AWT_WM_NONREPARENTING=1
```

## Useful applications
- atool for extracting and compressing any type of file
- tabliss extension for brave

## testing
- **[TODO]** bt-dualboot

