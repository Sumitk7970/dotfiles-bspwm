#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Usage: extract <path/file_name>.<zip|rar|bz2|gz|tar|tbz2|tgz|Z|7z|xz|ex|tar.bz2|tar.gz|tar.xz|.zlib|.cso>"
    echo "       extract <path/file_name_1.ext> [path/file_name_2.ext] [path/file_name_3.ext]"
    exit 1
fi

extract () {
    for arg in $@ ; do
        if [ ! -f $arg ]; then
            echo "$n - File doesn't exists"
            exit 1
        fi

        case $arg in
            *.tar.bz2)  tar xjf $arg      ;;
            *.tar.gz)   tar xzf $arg      ;;
            *.bz2)      bunzip2 $arg      ;;
            *.gz)       gunzip $arg       ;;
            *.tar)      tar xf $arg       ;;
            *.tbz2)     tar xjf $arg      ;;
            *.tgz)      tar xzf $arg      ;;
            *.zip)      unzip $arg        ;;
            *.Z)        uncompress $arg   ;;
            *.rar)      rar x $arg        ;;  
            *.jar)      jar -xvf $arg     ;;  
            *)          echo "'$arg' unknown archieve method" ;;
        esac
    done
}

extract $@
