/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pol <pol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:16 by pol               #+#    #+#             */
/*   Updated: 2026/01/06 11:32:57 by pol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat boss("The Boss", 1);
		Bureaucrat intern("Intern", 150);
		Form taxForm("Tax-28B", 50, 25);

		std::cout << boss << std::endl;
		std::cout << intern << std::endl;
		std::cout << taxForm << std::endl;

		std::cout << "\n--- Intern tries to sign ---" << std::endl;
		intern.signForm(taxForm);

		std::cout << "\n--- Boss tries to sign ---" << std::endl;
		boss.signForm(taxForm);

		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}