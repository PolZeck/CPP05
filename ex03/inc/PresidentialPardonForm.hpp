/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:46:44 by pol               #+#    #+#             */
/*   Updated: 2026/01/21 09:51:57 by pledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

/**
 * CONCRETE CLASS PresidentialPardonForm
 * Required grades: Sign 25, Exec 5. 
 * Inherits from AForm. 
 */
class PresidentialPardonForm : public AForm
{
private:
    const std::string _target; // Target of the pardon (e.g., a person's name) [cite: 203]

public:
    // Orthodox Canonical Form
    PresidentialPardonForm(); 
    PresidentialPardonForm(const std::string &target); // Main constructor [cite: 203]
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    virtual ~PresidentialPardonForm();

    /**
     * Implementation of the pure virtual function from AForm.
     * Informs that the target has been pardoned by Zaphod Beeblebrox. [cite: 202]
     */
    virtual void execute(Bureaucrat const &executor) const;
};

#endif