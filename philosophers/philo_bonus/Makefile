NAME = philo_bonus

SRC_DIR = src
OBJ_DIR = objs
HEADERS_DIR = includes

SRC_MANDATORY = init.c \
				parser.c \
				philo.c \
				utils.c \
				threads.c \
				routine.c
OBJ_MANDATORY = ${SRC_MANDATORY:.c=.o}
DEPS_MANDATORY = ${OBJ_MANDATORY:.o=.d}

SRC = $(addprefix $(SRC_DIR)/, $(SRC_MANDATORY))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_MANDATORY))
DEPS = ${OBJ:.o=.d}

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -MMD
RM = rm -rf

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	${RM} ${OBJ} ${OBJ_DIR}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re

-include ${DEPS}