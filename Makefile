CC = gcc
INCLUDES = ./headers
LIBRARIES = -lSDL2
FLAGS = -W

all: clean compile run

compile: game.o player.o
	$(CC) -o binary ./source/main.c game.o player.o -I $(INCLUDES) $(LIBRARIES) $(FLAGS)

game.o:
	gcc -c ./source/game.c -I $(INCLUDES)

player.o:
	gcc -c ./source/player.c -I $(INCLUDES)

clean:
	rm *o binary

run:
	./binary


