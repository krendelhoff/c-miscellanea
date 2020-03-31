.PHONY: all clean install uninstall cleanall

FLAGS = -Werror -Wall -Wextra

all: launch clean

clean:
		rm -rf *.o *.a

fclean: clean
		rm -rf binary

re: fclean all

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
		ar rc mylib.a *.o

launch: main.c lib.o
		gcc $(FLAGS) -o binary main.c mylib.a -I lib
