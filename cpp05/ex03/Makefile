# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 19:21:21 by ttiprez           #+#    #+#              #
#    Updated: 2026/09/25 14:11:51 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex02

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98

SRC			= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
INC			= Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
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
	$(RM) $(NAME) backyard_shrubbery

re: fclean all

.PHONY: all clean fclean rez