/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:18:02 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 09:51:26 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

/**
 * The Intern class acts as a Form Factory.
 * It has no attributes (name or grade) as per the subject. 
 */
class Intern
{
public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    /**
     * Main function: Creates a specific AForm based on string names. [cite: 228]
     * @param name Name of the form to create. [cite: 229]
     * @param target Target for the new form. [cite: 229]
     * @return A pointer to the newly allocated form, or NULL if name is invalid. 
     */
    AForm *makeForm(std::string name, std::string target);
};

#endif