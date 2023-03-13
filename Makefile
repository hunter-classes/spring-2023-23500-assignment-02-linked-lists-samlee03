main: main.o OList.o List.o Node.o
	g++ -o main main.o OList.o List.o Node.o

tests: tests.o OList.o List.o Node.o 
	g++ -o tests tests.o OList.o List.o Node.o 

main.o: main.cpp List.h OList.h Node.h

tests.o: tests.cpp List.h OList.h Node.h

OList.o: OList.cpp OList.h Node.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f main.o OList.o List.o Node.o tests.o

