NAME = container

CXX = c++
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98 -Iincludes -g -D_GLIBCXX_DEBUG#flag per debuggare

SRC 	= main.cpp Span.cpp
OBJ 	= $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re