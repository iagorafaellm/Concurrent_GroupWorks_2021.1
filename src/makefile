CC = gcc

all: main bmp.c concurrentmath.c

main: main.o bmp.o concurrentmath.o
	${CC} -o main main.o bmp.o concurrentmath.o -lm -lpthread

main.o: main.c
	${CC} -o main.o main.c -c -Wall -lm -w

bmp.o: bmp.c
	${CC} -c bmp.c -c -g -Wall -w

concurrentmath.c.o: concurrentmath.c
	${CC} -c concurrentmath.c.c -c -g -Wall -w

clean:
	rm -rf *.o *.bmp *~ main