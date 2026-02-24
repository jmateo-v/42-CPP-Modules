CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = btc

SRCS = BitcoinExchange.cpp\
	main.cpp

HDRS = BitcoinExchange.hpp

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