# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 19:21:21 by ttiprez           #+#    #+#              #
#    Updated: 2026/06/11 16:40:06 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex03

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
INC			= AMateria.hpp ICharacter.hpp Character.hpp Cure.hpp Ice.hpp IMateriaSource.hpp MateriaSource.hpp
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