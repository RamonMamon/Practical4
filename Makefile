CC = clang
FLAGS = -Wall -Wextra -O0

all: circuits
clean:
	rm -f *.o circuits

circuits: circuits.o parsing.o definitions.o
	${CC} ${FLAGS} circuits.o parsing.o definitions.o -o circuits

circuits.o: circuits.c parsing.h
	${CC} ${FLAGS} circuits.c -c -o circuits.o 

parsing.o : parsing.c parsing.h
	${CC} ${FLAGS} parsing.c -c -o parsing.o 

definitions.o : definitions.c definitions.h
	${CC} ${FLAGS} definitions.c -c -o definitions.o 