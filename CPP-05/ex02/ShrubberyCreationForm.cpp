/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayaraogioni <nayaraogioni@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:40:03 by nayaraogion       #+#    #+#             */
/*   Updated: 2026/05/01 15:55:26 by nayaraogion      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : 
                            AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
                            AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::performAction() const
{
    std::ofstream file;
    
    file.open((this->_target + "_shrubbery").c_str());
    if (!file)
    {
        std::cout << "ERROR: Could not create/open file." << std::endl;
        return ;
    }
    file << "   /\\   " << std::endl;
    file << "  /**\\  " << std::endl;
    file << " /****\\ " << std::endl;
    file << "   ||   " << std::endl;
    file.close();
}