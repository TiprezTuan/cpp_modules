# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 19:21:21 by ttiprez           #+#    #+#              #
#    Updated: 2026/10/01 15:01:25 by ttiprez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex03

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98

SRC			= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
INC			= Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
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

.PHONY: all clean fclean re