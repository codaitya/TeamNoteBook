"type :help quickref.txt to get shortcut full forms and meanings (search term with single quote)

"autocomplete
imap {<CR>  {<CR>}<Esc>O

"Considered standard
"nocompatible : turns on enhancements and improvements of vim
"cb = unnamedplus makes vim and system clipboard same
"noet : noexpandtab (tab only gives tab and not 4 spaces)
"bs = 2 : backspace recommended settings
set cul nocp ts=4 sw=4 noet ai cin bs=2 cb=unnamed nu ru wrap ar sc smd fdm=marker pt=<F2> mouse=a wmnu
syn on
filetype on

"autoindent code and make cursor in center of screen
nnoremap <F8> gg=G''zz 

"searches all strings if lower case used, searches exact matching if upper casae used, showing partial match
set scs ic is gd "smartcase, ignorecase, incsearch, /g is set globally by default(so use /g to access only first word in each line)

"for storing cursor location
if has("autocmd")
  au bufreadpost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif 
endi

"shortcuts for compile n run 
au FileType cpp set makeprg=g++\ -o\ %:p:r\ %:p\ -std=c++11\ -O2\ -fomit-frame-pointer
au FileType cpp  map <F9> :w<CR>:make<CR><CR><CR>
map <F5> :!%:p:r<CR>

map <F10> :cp<CR>
map <F11> :cn<CR>

set t_Co=256 "sets 16 colors in terminal used for colorscheme change

au BufNewFile *.cpp 0r ~/cpp.template "template


"not used
"set guicursor+=i:blinkwait10 "supposed to increase blink rate
"set paste "for pasting without losing indentation
"map <F9> :w<CR>:!clear<CR>:make<CR>
"imap <F9> <ESC>:w<CR>:!clear<CR>:make<CR>
"map <F5> :!clear<CR>:!%:p:r<CR>"compile and run shortcuts
"set background=dark
"let g:solarized_termcolors=16
"colorscheme simple_dark "colorscheme
":highlight cursorline ctermbg=blue "gives blue background highlighting

"pressing F6 switches search-highlighting off until the next time you search (need to enable set hls)
"nnoremap <F6> :noh<CR>
"inoremap <F6> <Esc>:noh<CR>a
"compile and run shortcuts
"insert  mode cpp 
"au filetype cpp inoremap <F4> <Esc> <bar> :w <bar> exec '!g++ -std=c++11 '.shellescape('%').' -o '.shellescape('%:r').' && echo Compiled Successfully and Running.... && ./'.shellescape('%:r')<CR>
"insert  mode c 
"au filetype c inoremap <F4> <Esc> <bar> :w <bar> exec '!gcc '.shellescape('%').' -o '.shellescape('%:r').' && echo Compiled Successfully and Running.... && ./'.shellescape('%:r')<CR>
"only run insert  mode cpp,c
""normal  mode cpp 
"au filetype cpp nnoremap <F4> :w <bar> exec '!g++ -std=c++11 -O2 -fomit-frame-pointer '.shellescape('%').' -o '.shellescape('%:r').' && echo Compiled Successfully and Running.... && ./'.shellescape('%:r')<CR>
"normal  mode c 
"au filetype c nnoremap <F4> :w <bar> exec '!gcc '-O2 -fomit-frame-pointer .shellescape('%').' -o '.shellescape('%:r').' && echo Compiled Successfully and Running.... && ./'.shellescape('%:r')<CR>
"only run
"normal  mode cpp,c
"au filetype cpp,c nnoremap <F5> :w <bar> exec '! echo Running Executable........ && ./'.shellescape('%:r')<CR>
"au filetype cpp,c inoremap <F5> <Esc> <bar> :w <bar> exec '! echo Running Executable........ && ./'.shellescape('%:r')<CR>
