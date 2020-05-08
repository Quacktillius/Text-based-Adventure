flags = -pedantic-errors -std=c++11 -Wall
begnc = -I local/include -I local/include/ncursestw -L local/lib
endnc = -lncursestw -ldl -pthread
nc = ncurses_has_been_set_up.txt

ncurses_has_been_set_up.txt:
	./compile_san.sh

windowDetails.o: windowDetails.cpp windowDetails.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $< $(endnc)

saveGame.o: saveGame.cpp saveGame.h windowDetails.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $< $(endnc)

mainMenu.o: mainMenu.cpp mainMenu.h saveGame.h windowDetails.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $< $(endnc)

roll.o: roll.cpp roll.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $< $(endnc)

newGame.o: newGame.cpp newGame.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $< $(endnc)

test.o: test.cpp test.h roll.h newGame.h saveGame.h mainMenu.h windowDetails.h $(nc)
	g++ $(flags) $(begnc) -o $@ -c $< $(endnc)

Game: windowDetails.o saveGame.o mainMenu.o roll.o newGame.o test.o $(nc)
	g++ $(flags) $(begnc) -o $@ -c $^ $(endnc)

run:
	./Game 2> log.txt

delnc:
	rm ncurses_has_been_set_up.txt
	rm -rf local repos
	echo "The ncurses files have been deleted"

.PHONY: run delnc

