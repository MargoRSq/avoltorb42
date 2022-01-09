SRC_DIR   = src
OBJ_DIR   = objs/

SRC_NAMES   =	ft_printf.c \
				specifiers_atoi.c \
				specifiers.c \
				nbr_utils.c \
				conv_utils.c \
				global_utils.c \
				putnbr_count.c \
				putnbr_prefix.c \
				putnbr_utils.c \
				putnbr_width.c \
				putstr_count.c  \
				putstr_utils.c  \
				putstr_width.c  \
				put_fillers.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAMES))
OBJ_FILES = ${SRC_NAMES:.c=.o}
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

DEPS		= ${OBJ:.o=.d}

HEDR		= headers/ft_printf.h

NAME		= libftprintf.a

CC			= cc
RM			= rm -rf

CFLAGS		= -Wall -Werror -Wextra
CPPFLAGS	= -MMD -I.
ARFLAGS		= rcs


all:	${NAME}

${NAME}:	${OBJ}
	ar ${ARFLAGS} ${NAME} $?

$(OBJ_DIR)%.o : $(SRC_DIR)%.c ${HEDR}
	@mkdir -p $(OBJ_DIR)
	${CC} -c ${CFLAGS} ${CPPFLAGS} $< -o $@

bonus:	${NAME}

clean:
	${RM} ${DEPS} ${OBJ} ${OBJ_DIR}

fclean:	clean
	${RM} ${NAME}

re:	fclean all


.PHONY: all bonus clean fclean re

-include ${DEPS}