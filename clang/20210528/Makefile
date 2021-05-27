NAME = name
SRCS = main.c \
	   first.c \
	   second.c
OBJS = $(SRCS:.c=.o)

CC = clang
Include = .
COMPILE = $(CC)
LINK = $(CC)

RM = rm -f

.PHONY: all clean fclean re
all:		$(NAME)
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean all

$(NAME):	$(OBJS)
			$(LINK) -o $@ $^
%.o:		%.c
			$(COMPILE) -o $@ -c $<
