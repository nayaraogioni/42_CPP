NAME = Forms
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I inc

SRCS =  src/main.cpp \
		src/Bureaucrat.cpp \
		src/AForm.cpp \
		src/PresidentialPardonForm.cpp \
		src/RobotomyRequestForm.cpp \
		src/ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS =   inc/Bureaucrat.hpp \
			inc/AForm.hpp \
			inc/PresidentialPardonForm.hpp \
			inc/RobotomyRequestForm.hpp \
			inc/ShrubberyCreationForm.hpp

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
