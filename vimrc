"autocomplete
inoremap {<CR>  {<CR>}<Esc>O
"considered standard
set cursorline
set nocp ts=4 sw=4 noet ai cin bs=2 cb=unnamed
set number ruler wrap autoread showcmd showmode fdm=marker nobackup
syntax on
":highlight CursorLine ctermbg=Blue
highlight CursorLine cterm=Underline
filetype on

au BufNewFile *.cpp 0r /home/monalal/headercpp.template

"insert  mode cpp 
autocmd filetype cpp inoremap <F4> <Esc> <bar> :w <bar> exec '!g++ -std=c++11 -O2 '.shellescape('%').' -o '.shellescape('%:r').' && echo Code Running.... && ./'.shellescape('%:r')<CR>
"normal  mode cpp 
autocmd filetype cpp nnoremap <F4> :w <bar> exec '!g++ -std=c++11 -O2 '.shellescape('%').' -o '.shellescape('%:r').' && echo Code Running.... && ./'.shellescape('%:r')<CR>
"insert  mode c 
autocmd filetype c inoremap <F4> <Esc> <bar> :w <bar> exec '!gcc '.shellescape('%').' -o '.shellescape('%:r').' && echo Code Running.... && ./'.shellescape('%:r')<CR>
"normal  mode c 
autocmd filetype c nnoremap <F4> :w <bar> exec '!gcc '.shellescape('%').' -o '.shellescape('%:r').' && echo Code Running.... && ./'.shellescape('%:r')<CR>
"template in insert mode
inoremap <F9> #include <bits/stdc++.h> <Enter>#define GCP(x)  printf ("Case #%d: ", x);<Enter>typedef long long ll<Enter>using namespace std; <Enter>int main() <Enter>{ <Enter>return 0; <Enter>}
"to paste without losing indendation
set pastetoggle=<F2>
"mouse active
set mouse=a
"searches all strings if lower case used, searches exact matching if upper casae used
set smartcase 
set ignorecase
" pressing j twice equivalent to escape
:imap jj <Esc>
"for storing pointer location
if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif 
endi

"not used
"set guicursor+=i:blinkwait10 "supposed to increase blink rate
"set paste "for pasting without losing indentation
"map <F9> :w<CR>:!clear<CR>:make<CR>
"imap <F9> <ESC>:w<CR>:!clear<CR>:make<CR>
"map <F5> :!clear<CR>:!%:p:r<CR>"compile and run shortcuts
"se t_Co=16 "sets 16 colors in terminal used for colorscheme change
"set background=dark
"let g:solarized_termcolors=16
"colorscheme simple_dark "colorscheme
