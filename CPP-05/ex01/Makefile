NAME = Form
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I inc

SRCS = src/main.cpp \
	   src/Bureaucrat.cpp \
	   src/Form.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS =   inc/Bureaucrat.hpp \
			inc/Form.hpp

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
