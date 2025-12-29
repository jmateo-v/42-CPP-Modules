CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = animals

SRCS = Animal.cpp\
	Dog.cpp\
	Cat.cpp\
	WrongAnimal.cpp\
	WrongCat.cpp\
	main.cpp

HDRS = Animal.hpp\
	Dog.hpp\
	WrongAnimal.hpp\
	WrongCat.hpp\
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