/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:55 by pol               #+#    #+#             */
/*   Updated: 2026/01/19 14:47:15 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	
	public:
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

		// Orthodox Canonical AForm
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		// Getters
		const std::string &getName() const;
		int getGrade() const;

		// Grade Manipulation
		void incrementGrade();
		void decrementGrade();

		void executeForm(AForm const &form) const;

		void signAForm(AForm &f);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif