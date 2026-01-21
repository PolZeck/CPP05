/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 09:50:23 by pledieu           #+#    #+#             */
/*   Updated: 2026/01/21 10:29:16 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm; // Forward declaration to prevent circular inclusion

class Bureaucrat
{
    private:
        const std::string _name; // Constant as required by subject
        int               _grade; // Range: 1 (High) to 150 (Low)

    public:
        // Custom exceptions inheriting from std::exception
        class GradeTooHighException : public std::exception {
            public: virtual const char *what() const throw();
        };
    
        class GradeTooLowException : public std::exception {
            public: virtual const char *what() const throw();
        };

        // Orthodox Canonical Form
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        // Getters
        const std::string &getName() const;
        int               getGrade() const;

        // Grade logic: Incrementing means 3 -> 2
        void incrementGrade();
        void decrementGrade();

        // Form interactions
        void executeForm(AForm const &form) const;
        void signForm(AForm &f);
};

// Operator overload for easy printing
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif