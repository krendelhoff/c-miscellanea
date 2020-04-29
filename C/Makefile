.PHONY: all clean install uninstall cleanall

FLAGS = -Werror -Wall -Wextra

NAME = binary

HEADER = ~/Projects/Algorithms/C/lib/header

SRC = lib/bitwise.c \
	  lib/convert.c \
	  lib/io.c \
	  lib/math.c \
	  lib/print.c \
	  lib/scan.c \
	  lib/search.c \
	  lib/sort.c \
	  lib/string.c \
	  lib/swap.c \
	  lib/year.c

all: $(NAME)

clean:
		rm -rf *.o

fclean: clean
		rm -rf $(NAME) lib.a

re: fclean all

install:
		install ./$(NAME) /usr/local/bin

uninstall:
		rm -rf /usr/local/bin/$(NAME)

lib.a: $(SRC)
		gcc -g -c $(SRC) -I $(HEADER)
		ar rc lib.a *.o
		rm -rf *.o

$(NAME): main.c lib.a
		gcc $(FLAGS) -o $(NAME) main.c lib.a -I $(HEADER)
