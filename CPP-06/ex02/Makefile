NAME = base
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Base.cpp \

OBJS = $(SRCS:.cpp=.o)

HEADERS =	Base.hpp \
			A.hpp \
			B.hpp \
			C.hpp

all: $(NAME)
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re