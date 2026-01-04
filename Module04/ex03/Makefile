CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = FFifitwasgood

SRCS = Amateria.cpp\
	Character.cpp\
	Ice.cpp\
	Cure.cpp\
	MateriaSource.cpp\
	main.cpp

HDRS = AMateria.hpp\
	ICharacter.hpp\
	Character.hpp\
	Ice.hpp\
	Cure.hpp\
	IMateriaSource.hpp\
	MateriaSource.hpp

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