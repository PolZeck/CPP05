/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:45:20 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 12:24:43 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream> // Required for file stream operations (creating the shrubbery file)

/**
 * CONCRETE CLASS ShrubberyCreationForm
 * Required grades: Sign 145, Exec 137. 
 */
class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target; // Name used for the output file: <target>_shrubbery

    public:
        // Orthodox Canonical Form
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();

        /**
         * Implementation of execute:
         * 1. Validates signature and executor grade. 
         * 2. Creates a file named <target>_shrubbery.
         * 3. Writes ASCII trees into the file.
         */
        virtual void execute(Bureaucrat const &executor) const;
};

#endif