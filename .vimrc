set number
set showcmd
set hls
filetype on
filetype indent on
filetype plugin on
colorscheme ron
set ts=4
set sw=4

nmap ,u :0,yank+<cr>
nmap ,y mkgg"+yG`k
nmap ,p "+p
nmap ,s :w<cr>:sh<cr>
nmap ,/ I//<esc>
nmap ,\ I<del><del><esc>
