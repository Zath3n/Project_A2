#ID:3132175, Name:Gabriel

CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -lncurses -lm

appGame: main.c levels.c levels.h npc.h npc.c player.c player.h
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY:

clean:
	rm -f *.o appGame

run: appGame
	./appGame
