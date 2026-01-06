/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pol <pol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:18:19 by pol               #+#    #+#             */
/*   Updated: 2026/01/06 12:22:47 by pol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}
Intern::~Intern() {}

AForm *Intern::makeForm(std::string name, std::string target)
{
	// Tableau des noms de formulaires valides
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};

	int i = 0;
	// On cherche l'index correspondant au nom
	while (i < 3 && formNames[i] != name)
		i++;

	// On utilise un switch sur l'index (beaucoup plus propre que des if/else imbriqués)
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
		std::cout << "Error: Intern cannot create '" << name << "' because it doesn't exist." << std::endl;
		return NULL;
	}
}