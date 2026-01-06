/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pol <pol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:20:16 by pol               #+#    #+#             */
/*   Updated: 2026/01/06 11:21:57 by pol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade is too low!";
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form " << f.getName() << " (signed: " << (f.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << f.getGradeToSign()
	   << ", grade to exec: " << f.getGradeToExecute() << ")";
	return os;
}