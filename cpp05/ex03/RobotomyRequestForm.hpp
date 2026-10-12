/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:20:08 by ttiprez           #+#    #+#             */
/*   Updated: 2026/10/12 14:44:44 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		// Special Member Function
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		// Operators
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

	private:
		std::string	_target;

		// Member Functions
		void	executeAction(Bureaucrat const & executor)	const;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */