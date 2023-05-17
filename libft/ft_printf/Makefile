NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Ilibft
RM			= rm -f
AR			= ar rc
RN			= ranlib

OBJ			= ${SRC:.c=.o}

SRC =		ft_printf.c		\
			ft_printf_util1.c	\
			ft_printf_util2.c	\
			ft_printf_util3.c

all:		${NAME}

${NAME}:	libft ${OBJ}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

libft:
			${MAKE} -C libft
			cp libft/libft.a ./${NAME}

clean:
			${RM} ${OBJ} ${BONUS_OBJ}
			${MAKE} -C libft clean

fclean:		clean
			${RM} ${NAME}
			${MAKE} -C libft fclean

re:			fclean all

.PHONY:		all libft clean fclean re
