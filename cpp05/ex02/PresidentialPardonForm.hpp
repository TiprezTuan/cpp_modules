/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:20:22 by ttiprez           #+#    #+#             */
/*   Updated: 2026/09/22 15:24:21 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		// Special Member Function
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		// Operators
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		// Member Functions
		void	executeAction(Bureaucrat const & executor)	const;

	private:
		std::string	_target;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */