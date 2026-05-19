/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:58:41 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/19 19:26:01 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

static void safeSign(Bureaucrat &b, AForm *f)
{
	if (!f)
	{
		std::cout << "Cannot sign: form is NULL\n";
		return;
	}
	b.signForm(*f);
}

static void safeExec(Bureaucrat &b, AForm *f)
{
	if (!f)
	{
		std::cout << "Cannot execute: form is NULL\n";
		return;
	}
	b.executeForm(*f);
}

int main()
{
	std::srand(std::time(NULL));

	std::cout << "\n===== Creating Bureaucrats =====\n\n";

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Middle", 50);
	Bureaucrat low("Low", 150);

	std::cout << boss << std::endl;
	std::cout << mid << std::endl;
	std::cout << low << std::endl;

	std::cout << "\n===== Intern  Creates Forms =====\n\n";

	Intern someIntern;

	AForm *shrub = someIntern.makeForm("ShrubberyCreationForm", "Garden");
	AForm *robot = someIntern.makeForm("RobotomyRequestForm", "Bender");
	AForm *pardon = someIntern.makeForm("PresidentialPardonForm", "Arthur Dent");

	std::cout << "\n===== Intern Tries Invalid Form =====\n\n";

	AForm *invalid = someIntern.makeForm("unknown form", "Nobody");

	std::cout << "\n===== Signing Forms =====\n\n";

	safeSign(low, shrub);
	safeSign(mid, robot);
	safeSign(boss, pardon);

	std::cout << "\n===== Executing Forms (Weak Bureaucrats) =====\n\n";

	safeExec(low, shrub);
	safeExec(mid, robot);
	safeExec(mid, pardon);

	std::cout << "\n===== Executing Forms (Boss Executes All) =====\n\n";

	safeSign(boss, shrub);
	safeExec(boss, shrub);
	safeExec(boss, robot);
	safeExec(boss, pardon);

	std::cout << "\n===== Cleaning Up =====\n\n";

	delete shrub;
	delete robot;
	delete pardon;
	delete invalid;

	return 0;
}
