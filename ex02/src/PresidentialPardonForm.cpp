/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:46:58 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 10:48:16 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default constructor initializing with specific elite grades: Sign 25, Exec 5
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("default_target") {}

// Main constructor used by the Intern to set the target
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

// Copy constructor transferring state through the abstract base class
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

// Assignment operator (unused for constant targets)
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    (void)other;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/**
 * execute: Final action of the form.
 * Checks for signature and if the bureaucrat is high-ranking enough (Grade 5).
 */
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    // Verification of signature status and executor authority
    if (!this->getIsSigned() || executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    // The presidential action message
    std::cout << _target << " a été pardonné par Zaphod Beeblebrox." << std::endl;
}