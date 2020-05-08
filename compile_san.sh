#!/bin/bash
path=`pwd`
touch ncurses_has_been_set_up.txt
mkdir local
mkdir repos
cd repos
git clone https://github.com/mirror/ncurses.git
cd ncurses
./configure --prefix $path/local --enable-widec --with-pthread
make -j
make -j install
cd ..
