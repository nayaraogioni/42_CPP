NAME = convert
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS =	ScalarConverter.hpp \

all: $(NAME)
$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery
re: fclean all
.PHONY: all clean fclean re
