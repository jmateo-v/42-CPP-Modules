CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = forms

SRCS = Bureaucrat.cpp\
	Form.cpp\
	main.cpp

HDRS = Bureaucrat.hpp\
	Form.hpp

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all