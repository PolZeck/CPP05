/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:46:08 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 12:24:40 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // Required for rand() to simulate 50% success rate

/**
 * CONCRETE CLASS RobotomyRequestForm
 * Required grades: Sign 72, Exec 45.
 */
class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target; // The entity to be robotomized

	public:
		// Orthodox Canonical Form
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm();

		/**
		 * Implementation of execute:
		 * 1. Checks if form is signed and executor grade is sufficient.
		 * 2. Makes drilling noises.
		 * 3. 50% chance to succeed in robotomizing the target.
		 */
		virtual void execute(Bureaucrat const &executor) const;
};

#endif