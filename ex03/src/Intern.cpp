/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:18:19 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 10:18:53 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// --- Orthodox Canonical Form ---
// The Intern has no member variables, so constructors and assignment are simple.
Intern::Intern() {}

Intern::Intern(const Intern &other) 
{ 
    (void)other; // Nothing to copy as Intern has no state
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other; 
    return *this; // Self-assignment check not needed for empty class
}

Intern::~Intern() {}

/**
 * makeForm: The "Factory" method.
 * It creates a specific form object on the heap based on the 'name' string.
 */
AForm *Intern::makeForm(std::string name, std::string target)
{
    // Array of valid form names for comparison
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};

    // Loop to find the index of the matching form name
    int i = 0;
    while (i < 3 && formNames[i] != name)
        i++;

    /**
     * Using a switch on the index 'i' to instantiate the correct class.
     * This avoids multiple if/else blocks and is cleaner.
     * We return a pointer to the base class (AForm*) to use polymorphism.
     */
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << name << std::endl;
        return new ShrubberyCreationForm(target);
    case 1:
        std::cout << "Intern creates " << name << std::endl;
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern creates " << name << std::endl;
        return new PresidentialPardonForm(target);
    default:
        // Handle cases where the name does not match any known form
        std::cout << "Error: Intern cannot create '" << name << "' because it doesn't exist." << std::endl;
        return NULL;
    }
}