NAME		= pipex
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OBJ			= $(SRC:.c=.o)

SRC =	main.c \

all:	$(NAME)

%.o : %.c
	${CC} -c -o $@ $^ -I./libft ${CFLAGS}
	
$(NAME):	$(OBJ) 
			${MAKE} -C libft	
			gcc -o ${NAME} ${OBJ} -L./libft -lft

libft:
			${MAKE} -C libft

clean:
			$(RM) $(OBJ)
			$(MAKE) -C libft clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C libft fclean

re:			fclean all

.PHONY:		all libft clean fclean re
