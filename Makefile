all: main.o pokemon.o 
	gcc -o pokemon main.o pokemon.o
	
main.o: main.c pokemon.h
	gcc -c main.c
	
pokemon.: pokemon.c pokemon.h
	gcc -c pokemon.c
	
run:
	./pokemon
	
clear:
	rm *.o
