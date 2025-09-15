#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scarlucc <scarlucc@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 16:46:25 by scarlucc          #+#    #+#              #
#    Updated: 2025/09/14 19:04:15 by scarlucc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = firstCanonicalForm

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

#--------Class files--------------------------------------#
CLASS_PATH = ./class
CLASS_SRC = $(wildcard $(CLASS_PATH)/*.cpp)
#---------------------------------------------------------#

#--------Source files-------------------------------------#
SRC_PATH = ./srcs
SRC_SRC = $(wildcard $(SRC_PATH)/*.cpp)
#---------------------------------------------------------#

#--------All source files---------------------------------#
SRC = $(CLASS_SRC) $(SRC_SRC)
#---------------------------------------------------------#

#--------Object files-------------------------------------#
OBJ = $(patsubst $(SRC_PATH)/%.cpp,.build/%.o,$(SRC_SRC)) \
      $(patsubst $(CLASS_PATH)/%.cpp,.build/%.o,$(CLASS_SRC))
#---------------------------------------------------------#

#----Rules----------------------------------------------------#
all: .build $(NAME)

#--------Compile program----------------------------------#
$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
#---------------------------------------------------------#

#--------Compile object files-----------------------------#
.build/%.o: $(SRC_PATH)/%.cpp | .build
	$(CC) $(FLAGS) -c $< -o $@

.build/%.o: $(CLASS_PATH)/%.cpp | .build
	$(CC) $(FLAGS) -c $< -o $@
#---------------------------------------------------------#

#--------Create build directory---------------------------#
.build:
	mkdir -p $@
#---------------------------------------------------------#

#--------Clean object files-------------------------------#
clean:
	@if [ -d .build ]; then \
		rm -rf .build \
		echo ; \
		echo "${BOLD}${YELLOW}Removed -> ${RED}.build${NO_COLOR}"; \
		echo "${BOLD}${YELLOW}Cleaned object files${NO_COLOR}"; \
	else \
		echo ; \
		echo "${BOLD}${GREEN}Nothing to be done for clean${NO_COLOR}"; \
	fi
#---------------------------------------------------------#

#--------Clean program------------------------------------#
fclean: clean
	@if [ -e $(NAME) ]; then \
		rm -f $(NAME); \
		echo; \
		echo "${BOLD}${YELLOW}Removed -> ${RED}${NAME}${NO_COLOR}"; \
	else \
		echo; \
		echo "${BOLD}${GREEN}Nothing to be done for fclean${NO_COLOR}"; \
	fi

#---------------------------------------------------------#

re: fclean all

.PHONY: all clean fclean re

#----Colors---------------------------------------------------#
NO_COLOR		=	\033[0m
BOLD			=	\033[1m
YELLOW			=	\033[33m
GREEN			=	\033[32m
BLUE			=	\033[34m
RED				=	\033[31m
#-------------------------------------------------------------#