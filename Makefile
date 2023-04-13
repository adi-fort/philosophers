NAME	= philo
FLAGS	= -Wall -Wextra -Werror
CC		= gcc ${FLAGS}
RM		= rm -f
SRC		= utils.c check_input.c main.c 
OBJ		= ${SRC:.c=.o}

.o:.c
	${CC} -c ${OBJ} $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${OBJ} -pthread -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
