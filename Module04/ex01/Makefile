CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = animals_mem

SRCS = Animal.cpp\
	Dog.cpp\
	Cat.cpp\
	Brain.cpp\
	main.cpp

HDRS = Animal.hpp\
	Dog.hpp\
	Brain.hpp\
	Cat.hpp

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