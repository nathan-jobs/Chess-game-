CFLAGS = -ansi -Wall -Wfatal-errors

CC = gcc
LDFLAGS = -lMLV

OBJ = main.o test.o case.o position.o affichage.o
	
echecs : $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) 

	
main.o : main.c test.h affichage.h 
test.o : test.c test.h affichage.h  position.h  case.h 
affichage.o : affichage.c affichage.h position.h 
position.o : position.c position.h case.h 
case : case.c case.h

%.o : %.c
	$(CC) -c $<  $(CFLAGS) 
	
clean : 
	rm -f *.o
	
mrproper : clean
	rm -f $@



