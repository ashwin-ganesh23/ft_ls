NAME = ls

CC = gcc

FLAGS =	-Wall -Wextra -Werror

CFILES = ./ft_ls.c

LIBFT = -L libft/ -lft

HEADERS = -I ./ft_ls.h -I ./libft

all: $(NAME)

$(NAME):
	cd libft && make all
	$(CC) $(FLAGS) $(CFILES) $(HEADERS) $(LIBFT) -o $(NAME)
	cd libft && make fclean

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
