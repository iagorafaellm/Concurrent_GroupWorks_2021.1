CC = gcc

all: main bmp.c

main: main.o bmp.o
	${CC} -o main main.o bmp.o

main.o: main.c
	${CC} -o main.o main.c -c -w -Wall

bmp.o: bmp.c
	${CC} -c bmp.c -c -g -Wall

clean:
	rm -rf *.o *.bmp *~ main