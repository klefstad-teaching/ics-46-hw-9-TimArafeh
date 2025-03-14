F = -std=c++20 -Wall -Wextra -Wpedantic -Wfatal-errors
Z = ICS46_hw9.zip
P1 = ladder
P2 = dijkstras

all: $(P1) $(P2)


ladder: src/ladder.cpp src/ladder_main.cpp src/ladder.h
	g++ $(F) src/ladder.cpp src/ladder_main.cpp -o $(P1)

dijkstras: src/dijkstras.cpp src/dijkstras_main.cpp src/dijkstras.h
	g++ $(F) src/dijkstras.cpp src/dijkstras_main.cpp -o $(P2)

clean:
	/bin/rm -f $(P1) $(P2) $(Z)

zip: clean
	zip $(Z) Makefile src/ladder.cpp src/ladder_main.cpp src/ladder.h \
	    src/dijkstras.cpp src/dijkstras_main.cpp src/dijkstras.h \
	    src/words.txt src/small.txt src/medium.txt src/large.txt src/largest.txt
