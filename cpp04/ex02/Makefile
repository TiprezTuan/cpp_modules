# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 19:21:21 by ttiprez           #+#    #+#              #
#    Updated: 2026/06/11 14:15:38 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex02

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp main.cpp
INC			= AAnimal.hpp Dog.hpp Cat.hpp Brain.hpp
OBJ			= $(SRC:.cpp=.o)

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean rez