/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:16 by pol               #+#    #+#             */
/*   Updated: 2026/01/20 14:24:31 by pledieu          ###   ########.fr       */
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
	Intern someRandomIntern;
	Bureaucrat boss("The Boss", 1);
	AForm *rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	if (rrf)
	{
		boss.signAForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	someRandomIntern.makeForm("coffee request", "Intern");

	return 0;
}