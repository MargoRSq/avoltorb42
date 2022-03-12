SRCS_CT = client.c \
	utils.c \

SRCS_SR = server.c \
	utils.c \

NAME_CT = client
NAME_SR = server

HEAD = minitalk.h

OBJ_CT = $(SRCS_CT:.c=.o)
OBJ_SR = $(SRCS_SR:.c=.o)

FLAGS = -g -Wall -Wextra -Werror

all:	$(NAME_CT) $(NAME_SR)

$(NAME_CT): $(OBJ_CT)
			gcc -o $(NAME_CT) $(OBJ_CT)

$(NAME_SR): $(OBJ_SR)
			gcc -o $(NAME_SR) $(OBJ_SR)

%.o:	%.c $(HEAD)
			gcc $(FLAGS) -c $< -o $@

clean_client:
	rm -f $(OBJ_CT)

clean_server:
	rm -f $(OBJ_SR)

clean: clean_client clean_server

fclean_client: clean_client
	rm -f $(NAME_CT)

fclean_server: clean_server
	rm -f $(NAME_SR)

fclean: fclean_client fclean_server

re: fclean all

.PHONY: all clean fclean re