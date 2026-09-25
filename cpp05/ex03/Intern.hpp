/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:12:34 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/25 14:48:19 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>
# include <exception>

// Class
class Intern
{
	public:
		// Nested Class
		class FormNameDoesNotExist: public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		// Special Member Function
		Intern();
		Intern(const Intern& others);
		~Intern();

		// Operator
		Intern&		operator=(const Intern& other);

		// Member Functions
		AForm*	makeForm(std::string formName, std::string target);
};

#endif /* INTERN_HPP */