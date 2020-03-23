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
				gcc -c -o algorithms.o lib/algorithms.c -I lib

myio.o: lib/myio.c
		gcc -c -o myio.o lib/myio.c -I lib

mymath.o: lib/mymath.c
		gcc -c -o mymath.o lib/mymath.c -I lib

lib.o: mymath.o algorithms.o myio.o
		gcc -o lib.o mymath.o algorithms.o myio.o
main.o: main.c
		gcc -c -o main.o main.c -I lib

launch: main.o algorithms.o myio.o mymath.o
	gcc -Wall -Werror -Wextra main.o algorithms.o myio.o mymath.o -o executable
	./executable
