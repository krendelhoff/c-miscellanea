.PHONY: all clean install uninstall cleanall

FLAGS = -Werror -Wall -Wextra

NAME = binary

SRC = lib/mymath.c lib/myio.c lib/algorithms.c

all: $(NAME)

clean:
		rm -rf *.o

fclean: clean
		rm -rf binary mylib.a

re: fclean all

install:
		install ./executable /usr/local/bin

uninstall:
		rm -rf /usr/local/bin/executable

mylib.a: $(SRC)
		gcc -g -c $(SRC) -I lib
		ar rc mylib.a *.o
		rm -rf *.o

$(NAME): main.c mylib.a
		gcc $(FLAGS) -o $(NAME) main.c mylib.a -I lib
