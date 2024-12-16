NAME = ft_ls

SRCS_DIR = ./srcs

SRCS = $(SRCS_DIR)/main.c

OBJS = $(SRCS:.c=.o)

CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g  -I libft/

libft:
	make -C libft

all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re libft