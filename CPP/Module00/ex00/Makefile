# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrice <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 10:19:25 by kbrice            #+#    #+#              #
#    Updated: 2023/04/11 08:38:01 by kbrice           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= megaphone

SRC		= megaphone.cpp
OBJ		= $(SRC:.cpp=.o)

GCC		= g++
FLAGS	= -Wall -Wextra -Werror -std=c++98

RESET	= 	\033[0m
GREEN 	= 	\033[38;5;46m
GREY 	= 	\033[38;5;8m
BLUE 	= 	\033[0;36m

all: $(NAME)

%.o: %.cpp
	@$(GCC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(GREY)|	Compiling...$(RESET)"
	@$(GCC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)|	Created executable ./$(NAME) $(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(BLUE)|	Removed .o files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)|	Removed executable file$(RESET)"

re: fclean all

.PHONY: all clean fclean re
