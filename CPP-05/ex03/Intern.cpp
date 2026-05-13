/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:04:57 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/13 15:28:30 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *createShrubbery(const std::string &target)
{
	AForm* shrub = new ShrubberyCreationForm (target);
	return shrub;
}

AForm *createPresidential(const std::string &target)
{
	AForm *presid = new PresidentialPardonForm(target);
	return presid;
}

AForm	*createRobotomy(const std::string &target)
{
	AForm *rob = new RobotomyRequestForm(target);
	return rob;
}

AForm *(*creators[3])(const std::string &) = {
	createShrubbery,
	createRobotomy,
	createPresidential
};

AForm   *Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formList[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (int i = 0; i < 3; i++)
    {
        if (formList[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
    }
    std::cout << "Intern could not create form because the name is unknown." << std::endl;
    return NULL;
}