/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayaraogioni <nayaraogioni@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:06:16 by nayaraogion       #+#    #+#             */
/*   Updated: 2026/05/01 15:03:30 by nayaraogion      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : 
                        AForm("PresidentialPardonForm", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
                        AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : 
                        AForm(other), _target(other._target) {};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::performAction() const
{
    std::cout << this->_target 
              << " has been pardoned by Zaphod Beeblebrox" 
              << std::endl;
}
