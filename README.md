# acm

The solutions of problems on online judge.

Prepare for the contest. Many code style are not good for a project.

If you would like use vim and my `.vimrc` to configure it, you may do as follow first.


# Ubuntu

First, you should install some software. Run these sentences.

``` shell
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install g++ vim vim-gnome
```


# Mac OS X

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

