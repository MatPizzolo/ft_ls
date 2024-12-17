NAME = ft_ls

SRCS_DIR = ./srcs

SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/arg-checker.c $(SRCS_DIR)/handler.c $(SRCS_DIR)/sort.c $(SRCS_DIR)/display/display.c $(SRCS_DIR)/display/listed.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -g -I libft #-Werror

libft:
	make -C libft

all: libft $(NAME)

$(NAME): $(OBJS) ./libft/libft.a 
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re libft