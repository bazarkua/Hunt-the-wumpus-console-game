CC=g++ -std=c++11
exe_file=prog

$(exe_file): prog.cpp gold.o pit.o room.o event.o bat.o wumpus.o game.o
	$(CC) prog.cpp gold.o pit.o room.o event.o bat.o wumpus.o game.o -o $(exe_file) 

gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

pit.o: pit.cpp pit.h
	$(CC) -c pit.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

bat.o: bat.cpp bat.h
	$(CC) -c bat.cpp

clean: 
	rm -f *.o $(exe_file)