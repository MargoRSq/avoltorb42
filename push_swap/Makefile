NAME = push_swap
NAME_CHECKER = checker

SRC_DIR = src
OBJ_DIR = objs
HEADERS_DIR = includes
MAPS_DIR = maps

SRC_GENERAL		  = check_args.c \
					utils.c \
					init.c \
					ft_split.c \
					stack_operations.c \
					stack_operations_utils.c \
					stack_push.c \
					stack_reverse.c \
					stack_rotate.c \
					stack_swap.c \
					sorting.c \
					ft_butterfly.c \
					lst_operations.c

SRC_MANDATORY = $(SRC_GENERAL) push_swap.c
SRC_BONUS 	  = $(SRC_GENERAL) checker.c \
		        gnl/get_next_line.c \
				gnl/get_next_line_utils.c

OBJ_MANDATORY = ${SRC_MANDATORY:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

DEPS_MANDATORY = ${OBJ_MANDATORY:.o=.d}
DEPS_BONUS = ${OBJ_BONUS:.o=.d}


SRC = $(addprefix $(SRC_DIR)/, $(SRC_MANDATORY))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_MANDATORY))
DEPS = ${OBJ:.o=.d}

SRC_B = $(addprefix $(SRC_DIR)/, $(SRC_BONUS))
OBJ_B = $(addprefix $(OBJ_DIR)/, $(OBJ_BONUS))
DEPS_B = ${OBJ_BONUS:.o=.d}

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -MMD
RM = rm -rf

all: $(NAME)

bonus: $(NAME_CHECKER)

$(OBJ_DIR)/%.o  : $(SRC_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/gnl
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_PRINTF) -o $(NAME)

$(NAME_CHECKER): $(OBJ_B)
	$(CC) $(OBJ_B) $(FT_PRINTF) -o $(NAME_CHECKER)

clean:
	${RM} ${OBJ} ${OBJ_DIR}

fclean:	clean
	${RM} ${NAME}

fbclean: clean
	${RM} ${NAME_CHECKER}

re:	fclean all

.PHONY: all bonus clean fclean fbclean re ft_printf

-include ${DEPS} ${DEPS_BONUS}