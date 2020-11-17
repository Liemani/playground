CFLAG = -Wall -Wextra -Werror
SRC = main.c 04_hello.c
OBJ = $(SRC:.c=.o)
NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAG) -o $@ $^

%.o: %.c
	gcc $(CFLAG) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
