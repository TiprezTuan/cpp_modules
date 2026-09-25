/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:19:33 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/22 15:49:43 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <exception>
# include <string>

// Class
class Bureaucrat;

class AForm
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// Special Member Functions
		AForm();
		AForm(std::string const name, int const gradeToSign, int const gradeToExec);
		AForm(const AForm& other);
		virtual ~AForm();

		// Operator	
		AForm& 			operator=(const AForm& other);

		// Getters / Setters
		std::string		getName(void)								const;
		bool			getIsSigned(void)							const;
		int				getGradeToSign(void)						const;
		int				getGradeToExec(void)						const;

		// Member Functions
		void			execute(Bureaucrat const & executor)		const;
		int				checkGrade(int grade);
		void			beSigned(Bureaucrat& b);
		
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExec;
		
	protected:
		virtual void	executeAction(Bureaucrat const & executor)	const = 0;
};

std::ostream& operator<<(std::ostream& o, const AForm& f);

#endif /* AFORM_HPP */