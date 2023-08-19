NAME = reinterpretCast
CXX = c++
CXXFLAGS =  -I. -std=c++98 -Wall -Werror -Wextra -MMD -MP
SRCS = $(wildcard *.cpp)
# OBJS = $(SRCS:.cpp=.o)
OBJS = $(patsubst %.cpp, ./$(DIR)/%.o, $(SRCS))

HEADER = $(wildcard *.hpp)

DIR = objs
DEPS = $(OBJS:%.o=%.d)
RM = rm -rf

# -include ${DEPS}

all: $(DIR) $(NAME) 

./$(DIR)/%.o: %.cpp $(HEADER) Makefile# | $(DIR)
	$(CXX) ${CXXFLAGS} -o $@ -c $<

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(DIR):
	mkdir -p $(DIR)

clean:
	$(RM) *.o *.d

fclean: clean
	$(RM) $(NAME) $(DIR)

re: fclean all

.PHONY: all clean fclean re
