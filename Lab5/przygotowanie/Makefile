$(CC) = gcc

przetwarzanie2: main.o funkcje.o 
			$(CC) main.o funkcje.o -o przetwarzanie2
main.o: main.c funkcje.h
		$(CC) -c main.c 

funkcje.o: funkcje.c funkcje.h
		$(CC) -c funkcje.c 


clean: 
		rm *.o przetwarzanie2