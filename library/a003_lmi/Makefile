SRCS  = FileManager.cpp ErrorHandler.cpp IOSDescriber.cpp test.cpp

OBJS  = ${SRCS:.cpp=.o}

NAME  = test

CPP   = clang++

.PHONY : all run
all : ${NAME}

run : all
	./${NAME}

${NAME} : ${OBJS}
	${CPP} -o ${NAME} ${OBJS}

%.o : %.cpp
	$(CPP) -o $@ -c $< -std=c++11

.PHONY : clean rerun
clean :
	rm -f ${OBJS}

rerun : clean run
