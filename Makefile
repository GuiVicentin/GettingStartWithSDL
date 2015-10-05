CC = gcc
INCLUDES = ./headers
LIBRARIES = -lSDL2
FLAGS = -W

compile:
	$(CC) -o binary ./source/main.c -I $(INCLUDES) $(LIBRARIES) $(FLAGS)

game.o:
	gcc -c ./source/game.c

player.o:
	gcc -c ./source/player.c

clean:
	rm *o binary

run:
	./binary


