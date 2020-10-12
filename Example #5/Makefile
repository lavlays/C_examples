SRCS	= ft_cat.c ft_putstr.c ft_strcmp.c
OBJS	= ${SRCS:.c=.o}

GCC	= gcc 
RM	= rm -f
CFLAGS	= -Wall -Wextra -Werror 

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

NAME	= ft_cat

${NAME}:	${OBJS}
	${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

.PHONY:	all clean fclean
