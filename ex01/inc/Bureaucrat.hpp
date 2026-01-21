/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:55 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 12:23:26 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;

    public:
        // --- Exceptions ---
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

        // --- Orthodox Canonical Form ---
        Bureaucrat(); 
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        // --- Getters ---
        const std::string &getName() const;
        int               getGrade() const;

        // --- Member Functions ---
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &f);
};

// --- Operator Overload ---
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif