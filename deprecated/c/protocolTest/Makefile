NAME		= food

SRCS		= main.c \
			  carrot.c \
			  cucumber.c \
			  food.c \
			  object.c
OBJS		= $(SRCS:.c=.o)



CC			= clang
COMPILE		= $(CC)



.PHONY:		all debug setdebug
all:		$(NAME)
debug:		setdebug $(NAME)
setdebug:
			$(eval OPTION = -g)

$(NAME):	$(OBJS)
			$(COMPILE) $(OPTION) -o $@ $^

%.o:		%.c
			$(COMPILE) $(OPTION) -o $@ -c $<

.PHONY:		clean fclean re
clean:
			rm -f $(OBJS)
fclean:		clean
			rm -f $(NAME)
re:			fclean all
