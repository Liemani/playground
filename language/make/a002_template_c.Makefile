NAME				= philo

SRCS_LMT_C_LIBRARY	= \
					  lmt_primitive_type/lmt_atoi.c \
					  lmt_primitive_type/lmt_atol.c \
					  lmt_primitive_type/lmt_byte_cpy.c \
					  lmt_primitive_type/lmt_is_digit.c \
					  lmt_primitive_type/lmt_is_space.c \
					  lmt_primitive_type/lmt_strcpy.c

SRCS				= \
					  $(addprefix lmt_c_library/,$(SRCS_LMT_C_LIBRARY)) \
					  helper/helper_itoa.c \
					  helper/helper_ltoa.c \
					  helper/lmt_atoi_eat_goal.c \
					  helper/lmt_atoi_philosopher_count.c \
					  helper/sleep_philosopher.c \
					  helper/timeval_init_argument.c \
					  pen/pen.c \
					  philosopher/philosopher_run.c \
					  philosopher/philosopher_type.c \
					  philosopher/philosopher_write_log.c \
					  simulator/simulator_create_threads.c \
					  simulator/simulator_run.c \
					  simulator/simulator_type.c \
					  timeval/timeval_method.c \
					  timeval/timeval_type.c \
					  main.c
OBJS				= $(SRCS:.c=.o)

CC					= clang
CFLAGS				= -Wall -Wextra -Werror
ABSTRACT_INCLUDE	= \
					  . \
					  lmt_c_library \
					  constant \
					  helper \
					  pen \
					  philosopher \
					  simulator \
					  timeval
INCLUDE				= $(addprefix -I ,$(ABSTRACT_INCLUDE))
LIBRARY				=
COMPILE				= $(CC) $(CFLAGS) $(INCLUDE) $(DEBUG_OPTION)
LINK				= $(CC) $(CFLAGS) $(INCLUDE) $(DEBUG_OPTION) $(LIBRARY)

RM					= rm -f



.PHONY:				all debug setdebug clean fclean re
all:				$(NAME)

debug:				clean setdebug $(NAME)
setdebug:
					$(eval DEBUG_OPTION = -g)

clean:
					$(RM) $(OBJS)
fclean:				clean
					$(RM) $(NAME)
re:					fclean all



$(NAME):			$(OBJS)
					$(LINK) -o $@ $^

%.o:				%.c
					$(COMPILE) -o $@ -c $<
