
# ███████╗░██████╗██╗░░██╗██████╗░░█████╗░
# ╚════██║██╔════╝██║░░██║██╔══██╗██╔══██╗
# ░░███╔═╝╚█████╗░███████║██████╔╝██║░░╚═╝
# ██╔══╝░░░╚═══██╗██╔══██║██╔══██╗██║░░██╗
# ███████╗██████╔╝██║░░██║██║░░██║╚█████╔╝
# ╚══════╝╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░

# init starship prompt
eval "$(starship init zsh)"

# run diyfetch at startup
diyfetch

# zsh home
export ZSH=$HOME/.config/zsh

#===========================================
#           history config
#===========================================
export HISTFILE=$ZSH/.zsh_history

# How many commands zsh will load to memory.
export HISTSIZE=10000

# How many commands history will save on file.
export SAVEHIST=10000

# History won't save duplicates.
setopt HIST_IGNORE_ALL_DUPS

# History won't show duplicates on search.
setopt HIST_FIND_NO_DUPS


# for case insensitive completion
zstyle ':completion:*' matcher-list '' 'm:{a-zA-Z}={A-Za-z}' 'r:|=*' 'l:|=* r:|=*'
autoload -Uz compinit && compinit

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
HYPHEN_INSENSITIVE="true"

# set autocd
setopt autocd

# set default editor
export EDITOR='nvim'

# set bat as manpager
export MANPAGER="sh -c 'col -bx | bat -l man -p'"

# for java awt applications not working properly
export _JAVA_AWT_WM_NONREPARENTING=1

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

#=====================================================
#                  add to path
#=====================================================
export PATH="/home/sumit/anaconda3/bin:$PATH"
export PATH="/home/sumit/.local/bin:$PATH"
export PATH="/home/sumit/.bin:$PATH"


# aliases
source ~/.config/zsh/aliases.zsh

# vi mode
bindkey -v

# autosuggestions
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh

# source catppuccin-macchiato zsh-syntax-highlighting theme
if [[ -f "$ZSH/catppuccin_macchiato-zsh-syntax-highlighting.zsh" ]]; then
  source "$ZSH/catppuccin_macchiato-zsh-syntax-highlighting.zsh"
fi

# zsh zsh-syntax-highlighting
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

# Load Angular CLI autocompletion.
# source <(ng completion script)

