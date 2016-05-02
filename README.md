# ACM

The solutions of problems on online judge.

Prepare for the contest. Many code style are not good for a project.

# Stack Overflow

Useful in Windows.
``` c++
#pragma comment(linker, "/STACK:102400000,102400000")
```

# Git

To let git show Chinese charactors in `git status`, do as follow.

``` shell
git config core.quotepath off
git config i18n.logoutputencoding utf8
git config i18n.commitencoding utf8
```

To let git remember your password in one hour(push by HTTPS), do as follow.
``` shell
git config credential.helper 'cache --timeout=3600'
```

# Vim (and some other) config

If you would like use vim and my `.vimrc` to configure it, you may do as follow first.


## Ubuntu

First, you should install some software. Run these sentences.

``` shell
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install g++ vim vim-gnome
```

## Mac OS X

First, you should install some software.

You should not use the origional vim, because it cannot copy and paste to system clipboard.

``` shell
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
brew update
brew install vim
brew link vim 
brew install git
```

To let `ls` commend has color in terminal, you should add these sentences to `~/.bash_profile`, and run `source ~/.bash_profile`.

``` shell
export CLICOLOR=1
export LSCOLORS=gxfxaxdxcxegedabagacad
export PS1='\[\033[01;33m\]\u@\h\[\033[01;31m\] \W\$\[\033[00m\] '
```

For mac, you may need to add these config to `.vimrc`
```
syntax on
set clipboard+=unnamed
```
