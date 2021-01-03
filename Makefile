CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g
LIBS= 
LDFLAGS =`sdl2-config --cflags --libs`
INCLUDES= ./include/*.h 
EXEC = pentominos
SRC = Pentominos.c ./Vues/*.c ./Controleur/*.c ./Pieces/*.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)

pentominos: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
	
%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

clean:
	rm -rf *.o *~
mrproper:
	rm -rf $(EXEC)
	

