/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:46:23 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 10:45:43 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Default constructor: Sets fixed grades (Sign: 72, Exec: 45)
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default_target") {}

// Parameterized constructor: Initializes the target
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

// Copy constructor: Copies attributes via the base class AForm
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

// Assignment operator: target is constant, so no data is transferred here
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    (void)other;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/**
 * execute: Performs the robotomy attempt.
 * Requires the form to be signed and the executor to have a grade of 45 or better.
 */
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    // Check both signature status and executor grade level
    if (!this->getIsSigned() || executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    // Mandatory sound effect output
    std::cout << "* Bruit de perceuse intense *" << std::endl;
    
    // Simulate 50% success rate using rand()
    if (std::rand() % 2)
        std::cout << _target << " a été robotomisé avec succès !" << std::endl;
    else
        std::cout << "La robotomie de " << _target << " a échoué." << std::endl;
}