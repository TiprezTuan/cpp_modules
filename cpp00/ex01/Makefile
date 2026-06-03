# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/02 19:40:17 by ttiprez           #+#    #+#              #
#    Updated: 2026/06/03 12:33:16 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= myAwesomePhoneBook

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= Contact.cpp PhoneBook.cpp main.cpp
HEADERS		= Contact.hpp PhoneBook.hpp
OBJ			= $(SRC:.cpp=.o)

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re