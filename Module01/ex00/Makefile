CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = BraiiiiiinnnzzzZ

SRCS = main.cpp\
    Zombie.cpp\
	newZombie.cpp\
	randomChump.cpp

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
