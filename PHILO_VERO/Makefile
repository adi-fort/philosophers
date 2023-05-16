NAME	= philo
FLAGS	= -Wall -Wextra -Werror #-fsanitize=thread -g -o1
CC		= gcc ${FLAGS}
RM		= rm -f
SRC		= utils.c check_input.c main.c death_time.c 
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
