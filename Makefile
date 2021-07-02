##
## EPITECH PROJECT, 2020
## Makefile
## File description:
##  makefile
##

SRC			=		src/main.c 								\
					src/check_error.c						\
					src/utils.c								\
					src/init_soko.c							\
					src/my_sokoban.c						\
					src/end_condition.c						\
					src/key_press.c							\
\
					src/movement/move_up.c					\
					src/movement/move_down.c				\
					src/movement/move_left.c				\
					src/movement/move_right.c				\

OBJ 		= 		$(SRC:.c=.o)

NAME 		=		my_sokoban

CFLAGS 		= 		-I./include

LIB 		=		-L./lib/my -lmy -lncurses

all: $(NAME)

$(NAME): 		$(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
		rm -f $(OBJ)
		$(RM) *.gc*
		$(RM) tests/*.o
		$(RM) tests/*.gc*
		$(RM) src/*.gc*
		$(RM) src/*.o
		$(RM) lib/my/*.o

fclean:		clean
		$(RM) -f $(NAME) *.gc*
		$(RM) -f $(NAME) tests/*.gc*
		$(RM) tests/*.o
		$(RM) *.o
		$(RM) ../lib/my/*.o
		$(RM) unit_tests
		$(RM) calc

re: 	fclean all

tests_run:
		make -C tests/

.PHONY  : all clean fclean re test