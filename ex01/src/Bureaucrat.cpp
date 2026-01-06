/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pol <pol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:12 by pol               #+#    #+#             */
/*   Updated: 2026/01/06 11:29:06 by pol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// --- Exception Implementation ---

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Exception: Grade is too high (must be 1 or higher)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Exception: Grade is too low (must be 150 or lower)";
}

// --- Orthodox Canonical Form & Parameterized Constructor ---

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
	// Required format: <name>, bureaucrat grade <grade>.
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		// On tente d'appeler beSigned du formulaire
		f.beSigned(*this);
		// Si aucune exception n'est lancée, on affiche le succès
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		// Si beSigned lance une GradeTooLowException, on affiche l'erreur et la raison
		std::cout << _name << " couldn't sign " << f.getName()
				  << " because " << e.what() << std::endl;
	}
}