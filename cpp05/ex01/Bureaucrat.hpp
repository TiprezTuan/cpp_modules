/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:42:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/16 16:29:33 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <exception>
# include <string>

// Class
class Form;

class Bureaucrat
{
	public:
		// Nested Class
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		// Special Member Functions
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		// Operator
		Bureaucrat& operator=(const Bureaucrat& other);

		// Getters / Setters
		std::string getName(void) const;
		int			getGrade(void) const;

		// Member functions
		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(Form& f);

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

#endif /* BUREAUCRAT_HPP */