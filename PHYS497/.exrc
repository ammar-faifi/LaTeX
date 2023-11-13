let s:cpo_save=&cpo
set cpo&vim
cnoremap <silent> <C-R> <Cmd>lua require("which-key").show("\18", {mode = "c", auto = true})
inoremap <silent> <C-R> <Cmd>lua require("which-key").show("\18", {mode = "i", auto = true})
cnoremap <silent> <Plug>(TelescopeFuzzyCommandSearch) e "lua require('telescope.builtin').command_history { default_text = [=[" . escape(getcmdline(), '"') . "]=] }"
inoremap <C-B> ^i
inoremap <C-J> <Down>
inoremap <C-H> <Left>
inoremap <C-L> <Right>
inoremap <C-K> <Up>
inoremap <C-W> u
inoremap <C-U> u
nnoremap  <Cmd> %y+ 
nnoremap  h
nnoremap <NL> j
nnoremap  k
nnoremap  l
nnoremap  <Cmd> NvimTreeToggle 
nnoremap  <Cmd> w 
nnoremap <silent> Þ <Nop>
nnoremap <silent>  <Cmd>lua require("which-key").show("\23", {mode = "n", auto = true})
tnoremap  
nnoremap  :noh 
nnoremap <silent>  pÞ <Nop>
nnoremap <silent>  cÞ <Nop>
nnoremap <silent>  gÞ <Nop>
nnoremap <silent>  mÞ <Nop>
nnoremap <silent>  wÞ <Nop>
nnoremap <silent>  fÞ <Nop>
nnoremap <silent>  tÞ <Nop>
nnoremap <silent>  rÞ <Nop>
nnoremap <silent>  Þ <Nop>
nnoremap <silent>   <Cmd>lua require("which-key").show(" ", {mode = "n", auto = true})
xnoremap <silent>  Þ <Nop>
xnoremap <silent>   <Cmd>lua require("which-key").show(" ", {mode = "v", auto = true})
nnoremap  e <Cmd> NvimTreeFocus 
nnoremap  ma <Cmd> Telescope marks 
nnoremap  fz <Cmd> Telescope current_buffer_fuzzy_find 
nnoremap  ff <Cmd> Telescope find_files 
nnoremap  th <Cmd> Telescope themes 
nnoremap  gt <Cmd> Telescope git_status 
nnoremap  fh <Cmd> Telescope help_tags 
nnoremap  pt <Cmd> Telescope terms 
nnoremap  fo <Cmd> Telescope oldfiles 
nnoremap  fw <Cmd> Telescope live_grep 
nnoremap  fb <Cmd> Telescope buffers 
nnoremap  cm <Cmd> Telescope git_commits 
nnoremap  fa <Cmd> Telescope find_files follow=true no_ignore=true hidden=true 
vnoremap  / <Cmd>lua require('Comment.api').toggle.linewise(vim.fn.visualmode())
nnoremap  rn <Cmd> set rnu! 
nnoremap  b <Cmd> enew 
nnoremap  ch <Cmd> NvCheatsheet 
nnoremap  n <Cmd> set nu! 
nnoremap <silent> !aÞ <Nop>
nnoremap <silent> !iÞ <Nop>
nnoremap <silent> !Þ <Nop>
nnoremap <silent> ! <Cmd>lua require("which-key").show("!", {mode = "n", auto = true})
nnoremap <silent> " <Cmd>lua require("which-key").show("\"", {mode = "n", auto = true})
xnoremap <silent> " <Cmd>lua require("which-key").show("\"", {mode = "v", auto = true})
xnoremap # y?\V"
nnoremap & :&&
nnoremap <silent> ' <Cmd>lua require("which-key").show("'", {mode = "n", auto = true})
xnoremap * y/\V"
nnoremap <silent> <aÞ <Nop>
nnoremap <silent> <iÞ <Nop>
nnoremap <silent> <Þ <Nop>
nnoremap <silent> < <Cmd>lua require("which-key").show("<", {mode = "n", auto = true})
vnoremap < <gv
nnoremap <silent> >aÞ <Nop>
nnoremap <silent> >iÞ <Nop>
nnoremap <silent> >Þ <Nop>
nnoremap <silent> > <Cmd>lua require("which-key").show(">", {mode = "n", auto = true})
vnoremap > >gv
nnoremap Y y$
nnoremap <silent> [Þ <Nop>
nnoremap <silent> [ <Cmd>lua require("which-key").show("[", {mode = "n", auto = true})
nnoremap <silent> ]Þ <Nop>
nnoremap <silent> ] <Cmd>lua require("which-key").show("]", {mode = "n", auto = true})
nnoremap <silent> ` <Cmd>lua require("which-key").show("`", {mode = "n", auto = true})
nnoremap <silent> caÞ <Nop>
nnoremap <silent> ciÞ <Nop>
nnoremap <silent> cÞ <Nop>
nnoremap <silent> c <Cmd>lua require("which-key").show("c", {mode = "n", auto = true})
nnoremap <silent> dÞ <Nop>
nnoremap <silent> d <Cmd>lua require("which-key").show("d", {mode = "n", auto = true})
nnoremap <silent> diÞ <Nop>
nnoremap <silent> di <Cmd>lua require("which-key").show("di", {mode = "n", auto = true})
nnoremap <silent> daÞ <Nop>
nnoremap <silent> gUaÞ <Nop>
nnoremap <silent> gUiÞ <Nop>
nnoremap <silent> gUÞ <Nop>
nnoremap <silent> g~aÞ <Nop>
nnoremap <silent> g~iÞ <Nop>
nnoremap <silent> g~Þ <Nop>
nnoremap <silent> guaÞ <Nop>
nnoremap <silent> guiÞ <Nop>
nnoremap <silent> guÞ <Nop>
nnoremap <silent> gÞ <Nop>
nnoremap <silent> g <Cmd>lua require("which-key").show("g", {mode = "n", auto = true})
xnoremap <silent> gÞ <Nop>
xnoremap <silent> g <Cmd>lua require("which-key").show("g", {mode = "v", auto = true})
nnoremap <expr> j v:count || mode(1)[0:1] == "no" ? "j" : "gj"
xnoremap <expr> j v:count || mode(1)[0:1] == "no" ? "j" : "gj"
nnoremap <expr> k v:count || mode(1)[0:1] == "no" ? "k" : "gk"
xnoremap <expr> k v:count || mode(1)[0:1] == "no" ? "k" : "gk"
xnoremap <silent> p p:let @+=@0:let @"=@0
nnoremap <silent> vÞ <Nop>
nnoremap <silent> v <Cmd>lua require("which-key").show("v", {mode = "n", auto = true})
nnoremap <silent> vaÞ <Nop>
nnoremap <silent> viÞ <Nop>
nnoremap <silent> yaÞ <Nop>
nnoremap <silent> yiÞ <Nop>
nnoremap <silent> yÞ <Nop>
nnoremap <silent> y <Cmd>lua require("which-key").show("y", {mode = "n", auto = true})
nnoremap <silent> zÞ <Nop>
nnoremap <silent> z <Cmd>lua require("which-key").show("z", {mode = "n", auto = true})
nnoremap <silent> zfaÞ <Nop>
nnoremap <silent> zfiÞ <Nop>
nnoremap <silent> zfÞ <Nop>
nnoremap <silent> <C-W>Þ <Nop>
nnoremap <silent> <C-W> <Cmd>lua require("which-key").show("\23", {mode = "n", auto = true})
nnoremap <Plug>PlenaryTestFile :lua require('plenary.test_harness').test_file(vim.fn.expand("%:p"))
nnoremap <C-N> <Cmd> NvimTreeToggle 
tnoremap <C-X> 
nnoremap <C-S> <Cmd> w 
nnoremap <C-J> j
nnoremap <C-H> h
nnoremap <expr> <Up> v:count || mode(1)[0:1] == "no" ? "k" : "gk"
nnoremap <expr> <Down> v:count || mode(1)[0:1] == "no" ? "j" : "gj"
nnoremap <C-C> <Cmd> %y+ 
nnoremap <C-K> k
vnoremap <expr> <Down> v:count || mode(1)[0:1] == "no" ? "j" : "gj"
vnoremap <expr> <Up> v:count || mode(1)[0:1] == "no" ? "k" : "gk"
nnoremap <C-L> l
inoremap  ^i
inoremap  <Left>
inoremap <NL> <Down>
inoremap  <Up>
inoremap  <Right>
cnoremap <silent>  <Cmd>lua require("which-key").show("\18", {mode = "c", auto = true})
inoremap <silent>  <Cmd>lua require("which-key").show("\18", {mode = "i", auto = true})
inoremap  u
inoremap  u
imap jj 
let &cpo=s:cpo_save
unlet s:cpo_save
set clipboard=unnamedplus
set expandtab
set fillchars=eob:\ 
set helplang=en
set ignorecase
set laststatus=3
set noloadplugins
set mouse=a
set packpath=/opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime
set noruler
set runtimepath=~/.config/nvim,~/.local/share/nvim/lazy/lazy.nvim,~/.local/share/nvim/lazy/cmp-path,~/.local/share/nvim/lazy/cmp-buffer,~/.local/share/nvim/lazy/cmp-nvim-lsp,~/.local/share/nvim/lazy/cmp-nvim-lua,~/.local/share/nvim/lazy/cmp_luasnip,~/.local/share/nvim/lazy/nvim-autopairs,~/.local/share/nvim/lazy/friendly-snippets,~/.local/share/nvim/lazy/LuaSnip,~/.local/share/nvim/lazy/nvim-cmp,~/.local/share/nvim/lazy/which-key.nvim,~/.local/share/nvim/lazy/telescope-fzf-native.nvim,~/.local/share/nvim/lazy/telescope.nvim,~/.local/share/nvim/lazy/venv-selector.nvim,~/.local/share/nvim/lazy/plenary.nvim,~/.local/share/nvim/lazy/null-ls.nvim,~/.local/share/nvim/lazy/nvim-lspconfig,~/.local/share/nvim/lazy/indent-blankline.nvim,~/.local/share/nvim/lazy/nvim-colorizer.lua,~/.local/share/nvim/lazy/gitsigns.nvim,~/.local/share/nvim/lazy/nvim-web-devicons,~/.local/share/nvim/lazy/nvim-treesitter,~/.local/share/nvim/lazy/ui,/opt/homebrew/Cellar/neovim/0.9.4/share/nvim/runtime,/opt/homebrew/Cellar/neovim/0.9.4/lib/nvim,~/.local/state/nvim/lazy/readme,~/.local/share/nvim/lazy/cmp-path/after,~/.local/share/nvim/lazy/cmp-buffer/after,~/.local/share/nvim/lazy/cmp-nvim-lsp/after,~/.local/share/nvim/lazy/cmp-nvim-lua/after,~/.local/share/nvim/lazy/cmp_luasnip/after
set shiftwidth=2
set shortmess=iToIstlxnfOF
set noshowmode
set smartcase
set smartindent
set softtabstop=2
set splitbelow
set splitright
set statusline=%!v:lua.require('nvchad.statusline.default').run()
set tabstop=2
set termguicolors
set timeoutlen=400
set undofile
set updatetime=250
set whichwrap=<>[]hl,b,s
set window=70
" vim: set ft=vim :
