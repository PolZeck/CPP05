/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 09:47:04 by pledieu           #+#    #+#             */
/*   Updated: 2026/01/21 09:48:25 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration to resolve circular dependency with Bureaucrat

/**
 * ABSTRACT CLASS AForm
 * The 'A' prefix stands for Abstract. This class cannot be instantiated directly.
 * It serves as a base for specific forms (Shrubbery, Robotomy, Presidential).
 */
class AForm
{
private:
    const std::string _name;           // Constant name of the form
    bool              _isSigned;       // Status of the form (signed or not)
    const int         _gradeToSign;    // Minimum grade required to sign
    const int         _gradeToExecute; // Minimum grade required to execute

    /**
     * Default constructor is private to enforce that every form 
     * must be created with a name and specific grades.
     */
    AForm();

public:
    // --- Nested Exception Classes ---
    // Inheriting from std::exception to allow try/catch blocks
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

    // --- Orthodox Canonical Form Requirements ---
    // Constructor with parameters
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    // Copy constructor
    AForm(const AForm &other);
    // Copy assignment operator
    AForm &operator=(const AForm &other);
    /**
     * Virtual destructor is MANDATORY for base classes to ensure 
     * correct cleanup of derived (child) classes.
     */
    virtual ~AForm();

    // --- Getters (Marked as const because they don't modify the object) ---
    const std::string &getName() const;
    bool              getIsSigned() const;
    int               getGradeToSign() const;
    int               getGradeToExecute() const;

    // --- Core Logic Member Functions ---
    /**
     * beSigned: Checks if a Bureaucrat is high-graded enough to sign this form.
     * @param b The Bureaucrat attempting to sign.
     */
    void beSigned(const Bureaucrat &b);

    /**
     * PURE VIRTUAL FUNCTION (= 0)
     * This makes the class Abstract. Each derived class MUST implement 
     * its own 'execute' logic (Shrubbery creates files, Robotomy drills, etc.).
     */
    virtual void execute(Bureaucrat const &executor) const = 0;
};

/**
 * Operator overload for '<<'
 * Allows printing AForm details directly: std::cout << someForm << std::endl;
 */
std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif