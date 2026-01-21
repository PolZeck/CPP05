/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pol <pol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:20:16 by pol               #+#    #+#             */
/*   Updated: 2026/01/06 11:21:57 by pol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// --- Exception Messages ---
const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade is too low!";
}

// --- Constructor with Member Initializer List ---
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    // Validate grades during construction
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

// --- Copy Constructor ---
AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// --- Assignment Operator ---
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        // Only _isSigned is copied because other attributes are 'const'
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

// --- Getters ---
const std::string &AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

// --- Signing Logic ---
void AForm::beSigned(const Bureaucrat &b)
{
    // A bureaucrat can only sign if their grade is equal to or better (lower) than the requirement
    if (b.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

/**
 * OVERLOAD OF THE INSERTION OPERATOR (<<)
 * This is a global function (non-member) because the left operand is 'std::ostream'.
 * It allows printing a complete summary of any AForm object in a single line.
 */
std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "AForm " << f.getName() << " (signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to exec: " << f.getGradeToExecute() << ")";
    return os;
}