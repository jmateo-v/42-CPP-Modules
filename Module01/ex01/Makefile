CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = zombie_horde

SRCS = main.cpp\
    Zombie.cpp\
	zombieHorde.cpp

HDRS = Zombie.hpp

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
