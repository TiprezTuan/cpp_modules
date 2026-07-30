/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:42:10 by ttiprez           #+#    #+#             */
/*   Updated: 2026/07/30 17:54:32 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

// Class
class Bureaucrat
{
	public:
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