Gobang: main.o humanplayer.o computerplayer.o goboard.o
	g++ -Wall -o Gobang main.o humanplayer.o computerplayer.o goboard.o player.o

main.o: main.cpp humanplayer.h computerplayer.h goboard.h
	g++ -Wall -c main.cpp

goboard.o: goboard.cpp goboard.h
	g++ -Wall -c goboard.cpp

player.o: player.cpp player.h goboard.h
	g++ -Wall -c player.cpp

humanplayer.o: humanplayer.cpp humanplayer.h player.h
	g++ -Wall -c humanplayer.cpp

computerplayer.o: player.o computerplayer.cpp computerplayer.h player.h
	g++ -Wall -c computerplayer.cpp

clean:
	rm -f Gobang main.o goboard.o player.o humanplayer.o computerplayer.o

