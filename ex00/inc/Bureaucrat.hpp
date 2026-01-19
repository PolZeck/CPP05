/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:55 by pol               #+#    #+#             */
/*   Updated: 2026/01/19 14:42:26 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception> // Required for std::exception

class Bureaucrat
{
private:
	const std::string _name; // Constant name as required
	int _grade;				 // 1 (highest) to 150 (lowest)

	
	public:
	// --- Nested Exception Classes ---
	// Exception for grades higher than 1
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	
	// Exception for grades lower than 150
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	
	// --- Orthodox Canonical Form Requirements ---
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	// --- Getters ---
	const std::string &getName() const;
	int getGrade() const;

	// --- Grade Manipulation ---
	// Decreases the grade value (e.g., 3 -> 2), meaning a promotion
	void incrementGrade();
	// Increases the grade value (e.g., 149 -> 150), meaning a demotion
	void decrementGrade();
};

// --- Operator Overload ---
// Overload of the insertion (<<) operator for the required output format
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif