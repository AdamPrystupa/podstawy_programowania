$(CC) = gcc

po2: main.o opcje.o obsluga.o funkcje.o filtry.o funkcje.h 
			$(CC) main.o opcje.o obsluga.o funkcje.o filtry.o -o przetwarzanie2
main.o: main.c funkcje.h
		$(CC) -c main.c 

opcje.o: opcje.c funkcje.h
		$(CC) -c opcje.c 

filtry.o: filtry.c funkcje.h
		$(CC) -c filtry.c

obsluga.o: obsluga.c funkcje.h
		$(CC) -c obsluga.c

funkcje.o: funkcje.c funkcje.h
		$(CC) -c funkcje.c


clean: 
		rm *.o przetwarzanie2