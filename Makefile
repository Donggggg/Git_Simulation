client : main.o client.o 
		gcc main.o client.o -o client

main.o : main.c client.h
		gcc -c -W -Wall -Wextra main.c

client.o : client.c client.h
		gcc -c -W -Wall -Wextra client.c

clean :
	rm *.o
	rm client
