$(CC) = gcc

przetwarzanie2: main.o przetwarzanie.o opcje.o obsluga.o funkcje.h
			$(CC) main.o przetwarzanie.o opcje.o obsluga.o -o przetwarzanie2
main.o: main.c funkcje.h
		$(CC) -c main.c 

przetwarzanie.o: przetwarzanie.c funkcje.h
		$(CC) -c przetwarzanie.c 

opcje.o: opcje.c funkcje.h
		$(CC) -c opcje.c

obsluga.o: obsluga.c funkcje.h
		$(CC) -c obsluga.c


clean: 
		rm *.o przetwarzanie2