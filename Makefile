main: im.h main.o load_client.o run.o explode.o
	gcc -Wall -o main main.o load_client.o run.o explode.o

main.o: im.h main.c
	gcc -Wall -c main.c

load_client.o: im.h load_client.c
	gcc -Wall -c load_client.c

run.o: im.h run.c
	gcc -Wall -c run.c

explode.o: im.h explode.c
	gcc -Wall -c explode.c

clean:
	rm *.o
