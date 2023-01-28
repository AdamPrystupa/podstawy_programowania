$(CC) = gcc

kalkulator: main.o funkcje.o funkcje.h
			$(CC) main.o funkcje.o -o kalkulator
main.o: main.c funkcje.h
		$(CC) -c main.c 

funkcje.o: funkcje.c funkcje.h
		$(CC) -c funkcje.c 


clean: 
		rm *.o kalkulator