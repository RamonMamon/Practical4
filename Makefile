CC = clang
FLAGS = -Wall -Wextra -O0

all: circuits
clean:
	rm -f circuits

circuits: circuits.c
	${CC} ${FLAGS} circuits.c -o circuits

parsing.o : parsing.c definitions.h parsing.h
	${CC} ${FLAGS} parsing.c -c -o parsing.o 

definitions.o : definitions.c definitions.h
	${CC} ${FLAGS} definitions.c -c -o definitions.o 