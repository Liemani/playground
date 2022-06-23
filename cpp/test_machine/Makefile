TARGET_SRCS := a001_print_cin_at_getline.cpp \
               a002_fstream_open_close.cpp \
               a003_getsockopt_setsockopt.cpp \
               a004_readdir.cpp \
               a005_string.cpp
TARGET_OBJS := $(TARGET_SRCS:.cpp=.o)
TARGET := $(TARGET_SRCS:.cpp=)

UTIL_SRCS := util.cpp
UTIL_OBJS := $(UTIL_SRCS:.cpp=.o)

CXX := c++
CXXFLAGS := -std=c++98 -Wall -Wextra -Werror
INCLUDE := -I .
DEBUG_OPTION := -D NDEBUG
LIBRARY :=

COMPILE = $(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG_OPTION)
LINK = $(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG_OPTION) $(LIBRARY)

RM := rm -f



.PHONY: all
all: $(NAME)

.PHONY: debug setdebug
debug: clean setdebug $(NAME)
setdebug:; $(eval DEBUG_OPTION = -g)

.PHONY: clean fclean re
clean:; $(RM) $(TARGET_OBJS)
fclean: clean; $(RM) $(TARGET)
re: fclean all

.PHONY: echo
echo:; @echo CURDIR: $(CURDIR)
    @echo GITDIR: $(GITDIR)



$(TARGET): %: %.cpp $(UTIL_OBJS); $(LINK) -o $@ $^

$(UTIL_OBJS): %.o: %.cpp; $(COMPILE) -o $@ -c $<
