$(CC) = gcc

przetwarzanie2: main.o funkcje.o przetwarzaj_opcje.o
			$(CC) main.o funkcje.o przetwarzaj_opcje.o -o przetwarzanie2
main.o: main.c funkcje.h
		$(CC) -c main.c 

funkcje.o: funkcje.c funkcje.h
		$(CC) -c funkcje.c 

przetwarzaj_opcje.o: przetwarzaj_opcje.c funkcje.h
		$(CC) -c funkcje.c 

clean: 
		rm *.o przetwarzanie2