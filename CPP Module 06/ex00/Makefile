NAME = staticCast
CXX = c++
CXXFLAGS =  -I. -std=c++98 -Wall -Werror -Wextra -MMD -MP
SRCS = $(wildcard *.cpp)
# OBJS = $(SRCS:.cpp=.o)
OBJS = $(patsubst %.cpp, $(DIR)/%.o, $(SRCS))

HEADER = $(wildcard *.hpp)

DIR = objs
DEPS = $(OBJS:%.o=%.d)
RM = rm -rf

# -include ${DEPS}

all: $(NAME) $(DIR)

$(DIR)/%.o: %.cpp $(HEADER) Makefile | $(DIR)
	$(CXX) ${CXXFLAGS} -c $< -o $@

$(NAME): $(OBJS) $(DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(DIR):
	mkdir -p $(DIR)

clean:
	$(RM) *.o *.d

fclean: clean
	$(RM) $(NAME) $(DIR)

re: fclean all

.PHONY: all clean fclean re
