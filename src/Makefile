/********************************************************
 * @file makefile                 
 * @Makefile    
 * @author Kye R. ID:3143692 & Gabriel N. ID: 3132176                   
 * @date Dec. 9, 2025                  
 ********************************************************/


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

mem_valgrind: ./appGame
	valgrind --leak-check=full --show-leak-kinds=all ./appGame

doc:
	doxygen Doxyfile

run: appGame
	./appGame
