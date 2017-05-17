NAME = ls

CC = gcc

FLAGS =	-Wall -Wextra -Werror

CFILES =	./src/ft_ls.c
CFILES +=	./src/linked_list.c
CFILES +=	./src/sorts.c
CFILES +=	./src/check_flag.c
CFILES +=	./src/get_mode.c

LIBFT = -L libft/ -lft

HEADERS = -I ./includes/ft_ls.h -I ./libft

O_FILES = $(SRC:.c=.o)

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
