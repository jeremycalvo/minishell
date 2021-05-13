##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Evalexpr Makefile
##

SRC	=	src/main.c	\
		src/get_word.c	\
		src/cmd.c	\
		src/pwd.c	\
		src/exit.c	\
		src/env.c	\
		src/cd.c	\
		src/setenv.c	\
		src/setenv2.c	\
		src/list.c	\
		src/unsetenv.c	\
		src/search_cmd.c	\
		src/search_cmd2.c

LIB	=	lib/my/*.c

NAME	=	mysh

LNAME	=	libmy.a

all:
		cd lib/my/ && gcc -c *.c && ar rc $(LNAME) *.o
		cp lib/my/$(LNAME) lib/
		gcc -g3 -o $(NAME) $(SRC) -Llib/ -lmy -Iinclude/
		cd lib/my/ && rm -f *.o
		$(clean)

clean:
		cd lib/my/ && rm -f *.o
		rm -f *~
		rm -f *#
		cd lib/my/ && rm -f *~

fclean: clean
		rm -f $(NAME)
		rm -f lib/$(LNAME)
		rm -f lib/my/$(LNAME)
		rm -f vg*

re: fclean all