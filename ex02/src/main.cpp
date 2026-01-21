/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:16 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 10:26:29 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));

	std::cout << "-- Creation of bureaucrat --" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat manager("Manager", 50);
		Bureaucrat intern("Intern", 150);

		std::cout << "\n" << boss << std::endl;
		std::cout << manager << std::endl;
		std::cout << intern << "\n" << std::endl;

		std::cout << "-- Creation of the forms --" << std::endl;
		ShrubberyCreationForm shrub("home");
		ShrubberyCreationForm shrub2("home boss");
		std::cout << shrub << "\n" << std::endl;
		RobotomyRequestForm robo("Bender");
		std::cout << robo << "\n" << std::endl;
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << "\n" << std::endl;

		std::cout << "-- Execute without signature --" << std::endl;
		try
		{
			boss.executeForm(shrub);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		std::cout << "\n -- Signature --" << std::endl;
		intern.signForm(shrub);		// KO
		manager.signForm(pardon);	// KO
		manager.signForm(robo);		// OK but can't execute
		manager.signForm(shrub);	// OK
		boss.signForm(shrub2);		// OK
		boss.signForm(robo);		// OK
		boss.signForm(pardon);		// OK

		std::cout << "\n-- Execution of the forms --" << std::endl;

		std::cout << "\nIntern execution: " << std::endl;
		intern.executeForm(shrub);		// KO

		std::cout << "\nManager execution: " << std::endl;
		manager.executeForm(shrub);		// OK -> file _shrubbery
		manager.executeForm(robo);		// KO

		std::cout << "\nBoss execution: " << std::endl;
		boss.executeForm(shrub2);
		boss.executeForm(robo);			// OK
		boss.executeForm(robo);			// OK
		boss.executeForm(robo);			// OK
		boss.executeForm(robo);			// OK
		boss.executeForm(robo);			// OK
		boss.executeForm(pardon);		// OK

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}