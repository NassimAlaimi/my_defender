##
## EPITECH PROJECT, 2021
## My_Defender
## File description:
## Makefile
##

SRC := $(wildcard src/*.c)

OBJ 	= 		$(SRC:.c=.o)

CC		=		gcc

NAME	=		my_defender

CFLAGS 	= 		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -I./include -Werror -Wextra -Wshadow -W -Wall

LIB 	=		-L./lib/my -lmy

all: $(NAME)

$(NAME): 		$(OBJ)
		make -C lib/my/
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
		$(RM) $(OBJ)
		$(RM) ./lib/my/*.o

fclean:		clean
		$(RM) *.a
		$(RM) $(NAME)

re: 	fclean all
