/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pol <pol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:18:16 by pol               #+#    #+#             */
/*   Updated: 2025/12/02 15:20:15 by pol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Utility function to isolate tests and catch exceptions
void run_test(const std::string &title, void (*test_func)())
{
	std::cout << "\n--- Test: " << title << " ---" << std::endl;
	try
	{
		test_func();
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
}

// Test case 1: Normal instantiation, promotion, demotion, and stream output
void test_normal_operations()
{
	Bureaucrat b1("Regular Joe", 75);
	std::cout << b1 << std::endl;

	std::cout << "Promoting..." << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl;

	std::cout << "Demoting..." << std::endl;
	b1.decrementGrade(); // Back to 75
	b1.decrementGrade(); // Down to 76
	std::cout << b1 << std::endl;
}

// Test case 2: Instantiation with grade 0 (too high)
void test_invalid_high_instantiation()
{
	std::cout << "Attempting to create a Bureaucrat with grade 0..." << std::endl;
	Bureaucrat b2("The CEO", 0);
	std::cout << "Creation successful (SHOULD NOT HAPPEN): " << b2 << std::endl;
}

// Test case 3: Instantiation with grade 151 (too low)
void test_invalid_low_instantiation()
{
	std::cout << "Attempting to create a Bureaucrat with grade 151..." << std::endl;
	Bureaucrat b3("New Intern", 151);
	std::cout << "Creation successful (SHOULD NOT HAPPEN): " << b3 << std::endl;
}

// Test case 4: Attempt to increment grade 1
void test_max_grade_increment()
{
	Bureaucrat b4("The God", 1);
	std::cout << "Before promotion attempt: " << b4 << std::endl;
	std::cout << "Attempting to increment grade 1..." << std::endl;
	b4.incrementGrade();
	std::cout << "After promotion attempt (SHOULD NOT DISPLAY): " << b4 << std::endl;
}

// Test case 5: Attempt to decrement grade 150
void test_min_grade_decrement()
{
	Bureaucrat b5("The Coffee Maker", 150);
	std::cout << "Before demotion attempt: " << b5 << std::endl;
	std::cout << "Attempting to decrement grade 150..." << std::endl;
	b5.decrementGrade();
	std::cout << "After demotion attempt (SHOULD NOT DISPLAY): " << b5 << std::endl;
}

int main()
{
	run_test("Normal Operations", test_normal_operations);
	run_test("Invalid Grade (Too High) Instantiation", test_invalid_high_instantiation);
	run_test("Invalid Grade (Too Low) Instantiation", test_invalid_low_instantiation);
	run_test("Promotion past Grade 1", test_max_grade_increment);
	run_test("Demotion past Grade 150", test_min_grade_decrement);

	return 0;
}