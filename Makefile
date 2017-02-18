NAME = ls

CC = gcc

FLAGS =	-Wall -Wextra -Werror

CFILES = ./ft_ls.c

HEADERS = -I ./ft_ls.h

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(CFILES) $(HEADERS) -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
