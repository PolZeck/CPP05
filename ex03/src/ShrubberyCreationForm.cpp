/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pol <pol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:45:37 by pol               #+#    #+#             */
/*   Updated: 2026/01/06 11:53:41 by pol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::GradeTooLowException(); // Ou exception spécifique "non signé"
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (ofs.is_open())
	{
		ofs << "      /\\      " << std::endl;
		ofs << "     /\\*\\     " << std::endl;
		ofs << "    /\\O\\*\\    " << std::endl;
		ofs << "   /*/\\/\\/\\   " << std::endl;
		ofs << "  /\\*\\/\\*\\/\\  " << std::endl;
		ofs << "      ||      " << std::endl;
		ofs.close();
	}
}