##
## Makefile for  in /home/colnot_d
## 
## Made by dorian colnot
## Login   <colnot_d@epitech.net>
## 
## Started on  Tue Jun 19 15:11:40 2012 dorian colnot
## Last update Tue Jul  3 19:43:09 2012 dorian colnot
##

NAME	=	a.out

CC	=	gcc

SRC	=	list.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -g3 -std=c99

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all:		$(NAME)

clean:
	rm -vf $(OBJ)

fclean:		clean
	rm -vf all $(NAME)

re:	fclean all

.PHONY:	clean all fclean clean re
