set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set textwidth=80
set autoindent
set smartindent

autocmd filetype c,cpp set cin

highlight MoreThan80 ctermbg=blue guibg=blue
match MoreThan80 /\%81v.\+/

Bundle '42header'

let g:clang_library_path='/usr/lib/x86_64-linux-gnu/libclang-9.so.1'
let g:clang_snippets=1
let g:clang_snippets_engine = 'ultisnips'
let g:clang_hl_errors=1
let g:clang_close_preview=1
