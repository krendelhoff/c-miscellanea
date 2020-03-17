.PHONY: all clean install uninstall cleanall

all: launch

clean:
		rm -rf *.o

cleanall:
		rm -rf *.o executable

install:
		install ./executable /usr/local/bin

uninstall:
		rm -rf /usr/local/bin/executable

algorithms.o: lib/algorithms.c
				gcc -c -o algorithms.o lib/algorithms.c

myio.o: lib/myio.c
		gcc -c -o myio.o lib/myio.c

mymath.o: lib/mymath.c
		gcc -c -o mymath.o lib/mymath.c

main.o: main.c
		gcc -c -o main.o main.c

launch: main.o algorithms.o myio.o mymath.o
	gcc -o executable main.o algorithms.o myio.o mymath.o
	./executable
