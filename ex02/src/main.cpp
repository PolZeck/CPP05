/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:16 by pol               #+#    #+#             */
/*   Updated: 2026/01/19 13:25:09 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void run_test(const std::string &title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << "TEST: " << title << std::endl;
	std::cout << "========================================" << std::endl;
}

int main()
{
	std::srand(time(0));

	try
	{
		Bureaucrat boss("The Boss", 1);
		Bureaucrat mid("Mid-Level", 45);
		Bureaucrat intern("Intern", 140);

		// --- TEST 1 : Shrubbery (145 sign, 137 exec) ---
		run_test("Shrubbery Creation (home)");
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;

		intern.signAForm(shrub);   // OK (140 < 145)
		intern.executeForm(shrub); // KO (140 > 137)
		mid.executeForm(shrub);	   // OK (45 < 137)

		// --- TEST 2 : Robotomy (72 sign, 45 exec) ---
		run_test("Robotomy Request (Bender)");
		RobotomyRequestForm robo("Bender");

		intern.signAForm(robo); // KO (140 > 72)
		mid.signAForm(robo);	// OK (45 < 72)
		mid.executeForm(robo);	// OK (45 == 45) -> 50% de chance
		boss.executeForm(robo); // OK (1 < 45)

		// --- TEST 3 : Presidential Pardon (25 sign, 5 exec) ---
		run_test("Presidential Pardon (Arthur Dent)");
		PresidentialPardonForm pardon("Arthur Dent");

		mid.signAForm(pardon);	  // KO (45 > 25)
		boss.signAForm(pardon);	  // OK (1 < 25)
		mid.executeForm(pardon);  // KO (45 > 5)
		boss.executeForm(pardon); // OK (1 < 5)

		run_test("Execution sans signature");
		PresidentialPardonForm fake("Criminel");
		boss.executeForm(fake);
	}
	catch (std::exception &e)
	{
		std::cerr << "Main Exception Catch: " << e.what() << std::endl;
	}

	return 0;
}