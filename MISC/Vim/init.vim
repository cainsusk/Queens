set number relativenumber	"line numbering
set tabstop=4			"tab value when reading file 
set softtabstop=4		"and when writing them
set expandtab			"tabs as spaces
set autoindent
set cursorline			"power line

filetype on

"=-== Fuzzy File Finder but Built in ! ==-="
"
"the path is the files that is searched when you hit tab
"Adding ** says to search through all the directories and sub-directories 
"etc... To find the file you`re referencing i.e. It can find the file x/y/z
"from x by typing ``:find z`` and open it
"
"Additionally, the wild-menu command sets the 'wild menu' to appear when
"you hit tab in command mode.

set path+=**
set wildmenu

"=-== Tags ! =-=="
"
"Tags help us navigate throughout documents as well as are the basis for
"the built in auto-complete.
"Note the tags are kept in the dir : /usr/local/bin/ctags
"We build the tags recursively from the root of vim using the following
"command:

command! MakeTags !ctags -R .
set tags=/usr/local/bin/ctags 

"=-== Adds plug-vim ==-="
"
"if the current system does not have plug-vim prior to 
"to running (n)vim w/ this configuration, plug-vim will install 
"but the vim instance will fail. Once vim is run again, all should work
"well :)

let data_dir = has('nvim') ? stdpath('data') . '/site' : '~/.vim'
if empty(glob(data_dir . '/autoload/plug.vim'))
  silent execute '!curl -fLo '.data_dir.'/autoload/plug.vim --create-dirs  https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
  autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif

"=-== Plugins ! ==-="
"
"This is where plug-vim is used and where all the plugins i use are 
"called. Some of these may be useless but i`m still not sure because 
"this was copied an pasted of the inter-webs 0-0


call plug#begin()
" The default plugin directory will be as follows:
"   - Vim (Linux/macOS): '~/.vim/plugged'
"   - Vim (Windows): '~/vimfiles/plugged'
"   - Neovim (Linux/macOS/Windows): stdpath('data') . '/plugged'
" You can specify a custom plugin directory by passing it as the argument
"   - e.g. `call plug#begin('~/.vim/plugged')`
"   - Avoid using standard Vim directory names like 'plugin'

" Make sure you use single quotes

" Shorthand notation; fetches https://github.com/junegunn/vim-easy-align
Plug 'junegunn/vim-easy-align'

Plug 'SirVer/ultisnips' | Plug 'honza/vim-snippets'

Plug 'scrooloose/nerdtree'

"syntax checker
   Plug 'vim-syntastic/syntastic'
"  set statusline+=%#warningmsg#
"  set statusline+=%{SyntasticStatuslineFlag()}
"  set statusline+=%*
   let g:syntastic_check_on_wq = 1
   let g:syntastic_tex_checkers = ['chktex']

"Note Taking Plugins

Plug 'SirVer/ultisnips'
    let g:UltiSnipsExpandTrigger = '<tab>'
    let g:UltiSnipsJumpForwardTrigger = '<tab>'
    let g:UltiSnipsJumpBackwardTrigger = '<s-tab>'
    let g:UltiSnipsSnippetDirectories=["UltiSnips", "Ultisnips"]

Plug 'lervag/vimtex'
    let g:tex_flavor='latex'
    let g:vimtex_quickfix_mode=1
    let g:vimtex_compiler_method = 'latexmk'
    let g:vimtex_compiler_latexmk = {
        \ 'build_dir' : '',
        \ 'callback' : 1,
        \ 'continuous' : 1,
        \ 'executable' : 'latexmk',
        \ 'hooks' : [],
        \ 'options' : [
        \   '-verbose',
        \   '-file-line-error',
        \   '-synctex=1',
        \   '-interaction=nonstopmode',
        \ ],
        \}


Plug 'KeitaNakamura/tex-conceal.vim'
    set conceallevel=1
    let g:tex_conceal='abdmg'
    hi Conceal ctermbg=none

setlocal spell
set spelllang=en_us
inoremap <C-l> <c-g>u<Esc>[s1z=`]a<c-g>u

" Initialize plugin system
call plug#end()

