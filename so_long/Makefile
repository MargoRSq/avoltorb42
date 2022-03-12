NAME = so_long

SRC_DIR = src
OBJ_DIR = objs
HEADERS_DIR = includes
MAPS_DIR = maps

HEADER_GNL = $(HEADERS_DIR)/get_next_line.h
HEADER_SO_LONG = $(HEADERS_DIR)/so_long.h

SRC_NAMES = get_next_line_utils.c get_next_line.c draw_map.c free_utils.c check_map.c check_map_utils.c utils.c gameplay.c so_long.c
OBJ_NAMES = ${SRC_NAMES:.c=.o}
DEPS_NAMES = ${OBJ:.o=.d}

SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAMES))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAMES))
DEPS = ${OBJ:.o=.d}


CC = gcc -g
CFLAGS = -Wall
DEPS_FLAGS = -MMD
MINILIBX = -I -g -L /usr/X11/lib -Lincludes -L./mlx -lmlx -Imlx -lXext -lX11 -lz -lm -framework Opengl -framework AppKit
INCLUDES = -Imlx -I$(HEADERS_DIR)

RM			= rm -rf

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c ${HEADER_GNL} ${HEADER_SO_LONG} Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC)  $(CFLAGS) $(DEPS_FLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJ)
	$(CC)  $(OBJ) -o $(NAME) $(MINILIBX)

clean:
	${RM} ${DEPS} ${OBJ} ${OBJ_DIR}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all bonus clean fclean re

-include ${DEPS}