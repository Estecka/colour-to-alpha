SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = colour-to-alpha.out

CPPFLAGS = -Wall -Wextra
CXX = clang++

${NAME}: ${OBJS}
	${CXX} -o ${NAME} ${OBJS} ${CPPFLAGS}

clean:
	rm -f *.o

.phony: all clean fclean all
