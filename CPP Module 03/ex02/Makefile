NAME = FragTrap
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
