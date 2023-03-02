main: main.o List.o Node.o
	g++ -o main main.o List.o Node.o

main.o: main.cpp List.h Node.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f main.o List.o Node.o

