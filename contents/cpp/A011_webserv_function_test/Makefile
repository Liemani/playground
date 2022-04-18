CLIENT				:= client
SERVER				:= server

MAIN_FILE			:= A002_webserv_function_test_select.cpp

SRCS				:= \
					   $(MAIN_FILE)

OBJS				:= $(SRCS:.cpp=.o)

CXX					:= c++
CXXFLAGS			:= -std=c++98 -Wall -Wextra -Werror

INCLUDE				:= -I .

LIBRARY				:=

COMPILE				= $(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG_OPTION)
LINK				= $(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG_OPTION) $(LIBRARY)

RM					:= rm -f



.PHONY:				all debug setdebug clean fclean re
all:				$(CLIENT) $(SERVER)

debug:				clean setdebug $(CLIENT) $(SERVER)
setdebug:
					$(eval DEBUG_OPTION = -g)

clean:
					$(RM) $(OBJS)
fclean:				clean
					$(RM) $(CLIENT) $(SERVER)
re:					fclean all


$(CLIENT):			client.o
					$(LINK) -o $@ $^

client.o:			$(MAIN_FILE)
					$(COMPILE) -o client.o -c $< -D CLIENT

$(SERVER):			server.o
					$(LINK) -o $@ $^

server.o:			$(MAIN_FILE)
					$(COMPILE) -o server.o -c $< -D SERVER

%.o:				%.cpp
					$(COMPILE) -o $@ -c $<
