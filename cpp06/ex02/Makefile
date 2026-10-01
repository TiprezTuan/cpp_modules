# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 19:21:21 by ttiprez           #+#    #+#              #
#    Updated: 2026/10/01 15:01:14 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= identifyRealType

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98

SRC			= Base.cpp A.cpp B.cpp C.cpp main.cpp
INC			= Base.hpp A.hpp B.hpp C.hpp
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

.PHONY: all clean fclean re