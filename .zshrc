# init starship prompt
eval "$(starship init zsh)"

# source catppuccin-macchiato zsh-syntax-highlighting theme
if [[ -f "$HOME/.zsh/catppuccin_macchiato-zsh-syntax-highlighting.zsh" ]]; then
  source "$HOME/.zsh/catppuccin_macchiato-zsh-syntax-highlighting.zsh"
fi

#=====================================================
#                  add to path
#=====================================================
export PATH="/home/sumit/anaconda3/bin:$PATH"
export PATH="/home/sumit/.local/bin:$PATH"
export PATH="/home/sumit/.bin:$PATH"

# Path to your oh-my-zsh installation.
export ZSH="$HOME/.oh-my-zsh"

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
HYPHEN_INSENSITIVE="true"

#=====================================================
#                 zsh plugins
#=====================================================
plugins=(
  git
  autojump
  zsh-syntax-highlighting
  zsh-autosuggestions
  vi-mode
)

source $ZSH/oh-my-zsh.sh

# set default editor
export EDITOR='nvim'

# set bat as manpager
export MANPAGER="sh -c 'col -bx | bat -l man -p'"

# run pfetch at startup
pfetch

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

#=====================================================
#                  aliases
#=====================================================
alias update="sudo pacman -Syyu"
alias update-mirrors="sudo reflector --verbose --country 'India' -l 5 --sort rate --save /etc/pacman.d/mirrorlist"
alias vim=nvim
alias ii="sudo pacman -S"
alias rr="sudo pacman -Rns"
alias ss="pacman -Ss"
alias conf="nvim ~/.config/i3/config"
alias e="exit"
alias c="clear"
alias dot="/usr/bin/git --git-dir=$HOME/dotfiles/ --work-tree=$HOME"
alias la="ls -A"
alias mv="mv -i"
alias rm="rm -i"
alias v="vim"
alias gt="cd ~/Downloads/gitthings"
alias cat="bat"

