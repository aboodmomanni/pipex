CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft

SRC = pipex.c \
      utils.c \
      utils2.c \
      

OBJ = $(SRC:.c=.o)
NAME = pipex
LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
