/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:17:55 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/16 16:29:35 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

	# include "Bureaucrat.hpp"
# include <exception>
# include <string>

// Class
class Bureaucrat;

class Form
{
	public:
		// Nested Class
		class GradeTooHighException: public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// Special Member Functions
		Form();
		Form(std::string const name, int const gradeToSign, int const gradeToExec);
		Form(const Form& other);
		~Form();

		// Operator
		Form& operator=(const Form& other);

		// Getters / Setters
		std::string	getName(void)			const;
		bool		getIsSigned(void)		const;
		int			getGradeToSign(void)	const;
		int			getGradeToExec(void)	const;

		// Member Functions
		int		checkGrade(int grade);
		void	beSigned(Bureaucrat& b);

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExec;
};

std::ostream& operator<<(std::ostream& o, const Form& f);

#endif /* FORM_HPP */