CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Unnecesary_violence
SRCS = main.cpp\
    Weapon.cpp\
	HumanA.cpp\
	HumanB.cpp

HDRS = Weapon.hpp\
	HumanA.hpp\
	HumanB.hpp

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
