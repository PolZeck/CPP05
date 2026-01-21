/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:12 by pol               #+#    #+#             */
/*   Updated: 2026/01/20 13:38:39 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Default Constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	//no check needed because 150 is a valid grade
}

// --- Exception Implementation ---

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Exception: Grade is too high (must be 1 or higher)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Exception: Grade is too low (must be 150 or lower)";
}

// --- Orthodox Canonical AForm & Parameterized Constructor ---

// Parameterized Constructor: Checks grade limits and throws exceptions if invalid
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	_grade = grade;
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

// Assignment Operator: Only copies mutable members. _name is constant.
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// _name is constant, so only _grade is copied.
		_grade = other._grade;
	}
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// --- Getters ---

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// --- Grade Manipulation ---

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
	{ // Grade 1 is the highest
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
	{ // Grade 150 is the lowest
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

// --- Output Operator Overload ---

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	// Required AFormat: <name>, bureaucrat grade <grade>.
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

void Bureaucrat::signAForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		// if no exception, print success
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		// if besigned launch Gradetoolowexception, print error
		std::cout << _name << " couldn't sign " << f.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}