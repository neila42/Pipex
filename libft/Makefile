NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rc
RN			= ranlib

SRC = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_bzero.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memcpy.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_substr.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \

BONUS_SRC = ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \


OBJ			= ${SRC:.c=.o}
BONUS_OBJ	= ${BONUS_SRC:.c=.o}

all:		${NAME}

${NAME}:	${OBJ} ${BONUS_OBJ}
			ar rc ${NAME} $^
			ranlib ${NAME}

bonus:		${BONUS_OBJ}
			ar rc ${NAME} $^
			ranlib ${NAME}

clean:
			${RM} ${OBJ} ${BONUS_OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
