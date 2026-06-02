# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/02 19:40:17 by ttiprez           #+#    #+#              #
#    Updated: 2026/06/02 19:40:27 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = megaphone

CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC     = megaphone.cpp
OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re