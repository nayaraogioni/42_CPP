/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayaraogioni <nayaraogioni@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:09:15 by nayaraogion       #+#    #+#             */
/*   Updated: 2026/05/01 15:34:13 by nayaraogion      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() :
                        AForm("RobotomyRequestForm", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
                        AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : 
                        AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::performAction() const
{
    std::cout << "[SOME DRILLING NOISES]"
              << std::endl;
    if (std::rand() % 2 == 0)
    {
        std::cout << this->_target
                  << " has been robotomized successfully."
                  << std::endl;
    }
    else
        std::cout << this->_target
                  << " robotomy failed."
                  << std::endl;
}