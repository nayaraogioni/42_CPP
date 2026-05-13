/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:58:41 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/13 15:26:14 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

static void testForm(AForm *form, Bureaucrat &signer, Bureaucrat &executor)
{
	if (!form)
		return;

	std::cout << "\nCreated form: " << *form << std::endl;

	signer.signForm(*form);
	executor.executeForm(*form);

	delete form;
}

int main()
{
	std::srand(std::time(NULL));

	Intern intern;

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Middle", 50);
	Bureaucrat low("Low", 150);

	std::cout << "\n--- Intern creates valid forms ---" << std::endl;

	AForm *shrub = intern.makeForm("ShrubberyCreationForm", "home");
	AForm *robot = intern.makeForm("RobotomyRequestForm", "Bender");
	AForm *pardon = intern.makeForm("PresidentialPardonForm", "Arthur Dent");

	std::cout << "\n--- Test valid forms ---" << std::endl;

	testForm(shrub, boss, boss);
	testForm(robot, boss, boss);
	testForm(pardon, boss, boss);

	std::cout << "\n--- Intern receives invalid form name ---" << std::endl;

	AForm *unknown = intern.makeForm("coffee request", "Marvin");
	testForm(unknown, boss, boss);

	std::cout << "\n--- Test weak bureaucrat with intern-created form ---" << std::endl;

	AForm *robot2 = intern.makeForm("robotomy request", "Wall-E");
	if (robot2)
	{
		low.signForm(*robot2);
		mid.executeForm(*robot2);

		boss.signForm(*robot2);
		mid.executeForm(*robot2);
		boss.executeForm(*robot2);

		delete robot2;
	}

	return 0;
}
