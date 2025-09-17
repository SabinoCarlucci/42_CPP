#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/31 19:47:29 by scarlucc          #+#    #+#              #
#    Updated: 2025/09/17 14:24:17 by scarlucc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME    = HI_THIS_IS_BRAIN
CXX      = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC     = main.cpp
OBJ     = $(SRC:.cpp=.o)

#----Rules----------------------------------------------------#
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
