/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:16 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 10:29:04 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    // Instantiating the Intern (Factory) and a high-ranking Bureaucrat
    Intern someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    AForm *rrf; // Pointer to base class to demonstrate polymorphism

    // Testing successful form creation by the Intern
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    
    // Always check if the pointer is not NULL before using it
    if (rrf)
    {
        // Polymorphism: boss signs and executes without knowing the specific form type
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        
        // Intern used 'new', so we must manually 'delete' to prevent leaks
        delete rrf;
    }

    std::cout << "---------------------------------------" << std::endl;

    // Testing the Intern's error handling for an unknown form name
    someRandomIntern.makeForm("coffee request", "Intern");

    return 0;
}