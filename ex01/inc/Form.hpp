/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pol <pol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:21:19 by pol               #+#    #+#             */
/*   Updated: 2026/01/06 11:21:29 by pol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	// Orthodox Canonical Form
	Form();
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	// Getters
	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// Member function
	void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif