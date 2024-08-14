SRCS  = FileManager.cpp \
        ErrorHandler.cpp \
        IOSDescriber.cpp

OBJS  = ${SRCS:.cpp=.o}

TEST_SRCS = test.cpp

TEST_OBJS = ${TEST_SRCS:.cpp=.o}

TEST_NAME = test

CPP = clang++

.PHONY : all run
${TEST_NAME} : ${TEST_OBJS} ${OBJS}
	${CPP} -o ${TEST_NAME} ${TEST_OBJS} ${OBJS}

%.o : %.cpp
	$(CPP) -o $@ -c $< -std=c++11

.PHONY : clean rerun
clean :
	rm -f ${OBJS}

retest : clean test
