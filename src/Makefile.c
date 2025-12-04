#ID:3132175, Name:Gabriel

CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -lm

appGame: simpleMazeGame.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY:

clean:
	rm -f *.o appTestPart2.out

run: appGame
	./appGame
