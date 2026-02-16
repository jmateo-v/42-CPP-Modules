CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = intern

SRCS = Bureaucrat.cpp\
	AForm.cpp\
	ShrubberyCreationForm.cpp\
	RobotomyRequestForm.cpp\
	PresidentialPardonForm.cpp\
	Intern.cpp\
	main.cpp

HDRS = Bureaucrat.hpp\
	ShrubberyCreationForm.hpp\
	RobotomyRequestForm.hpp\
	PresidentialPardonForm.hpp\
	Intern.hpp\
	AForm.hpp

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all