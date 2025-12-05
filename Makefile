#Kye RIch

CC= gcc
CFLAGS= -Wall -std=c11
OBJS= maze1.o main.o

all: maze_test

maze_test: $(OBJS)
	$(CC) $(CFLAGS) -o maze_test $(OBJS) -lncurses

maze1.o: maze1.c maze1.h
	$(CC) $(CFLAGS) -c maze1.c

main.o: main.c maze1.h
	$(CC) $(CFLAGS) -c main.c


clean:
	rm -f *.o maze_test
