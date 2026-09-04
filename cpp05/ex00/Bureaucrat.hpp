/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:42:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/04 18:07:18 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>

// Class
class Bureaucrat
{
	public:
		// Nested Class
		class GradeTooHighException: public std::exception
		{
			private :
				std::string _message;
			
			public :
				explicit GradeTooHighException(const std::string &msg);
				const char* what() const noexcept override;
		};

		class GradeTooLowException: public std::exception
		{
			private :
				std::string _message;
			
			public :
				explicit GradeTooLowException(const std::string &msg);
				const char* what() const noexcept override;
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

	protected:
		const std::string	_name;
		int					_grade;
};

#endif /* BUREAUCRAT_HPP */