/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:45:37 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 10:42:43 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Default constructor calling base AForm with specific grades (Sign: 145, Exec: 137)
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default_target") {}

// Parameterized constructor initializing target and calling base constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// Copy constructor using base class copy mechanism
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

// Assignment operator (target is const, so nothing is copied here)
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    (void)other;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/**
 * execute: Implements the specific action for this form.
 * It verifies conditions and creates a file containing ASCII trees.
 */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    // Verification: Form must be signed
    if (!this->getIsSigned())
        throw AForm::GradeTooLowException();
    
    // Verification: Executor's grade must be sufficient
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    // Create and write to the file <target>_shrubbery
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (ofs.is_open())
    {
        ofs << "      /\\      " << std::endl;
        ofs << "     /\\*\\     " << std::endl;
        ofs << "    /\\O\\*\\    " << std::endl;
        ofs << "   /*/\\/\\/\\   " << std::endl;
        ofs << "  /\\*\\/\\*\\/\\  " << std::endl;
        ofs << "      ||      " << std::endl;
        ofs.close();
    }
}