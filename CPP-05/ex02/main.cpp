/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:58:41 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/13 13:21:36 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

/* int main()
{
	std::srand(std::time(NULL));

	std::cout << "\n--- Creating bureaucrats ---" << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Middle", 50);
	Bureaucrat low("Low", 150);

	std::cout << boss << std::endl;
	std::cout << mid << std::endl;
	std::cout << low << std::endl;

	std::cout << "\n--- Creating forms ---" << std::endl;

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	std::cout << "\n--- Test 1: execute unsigned forms ---" << std::endl;

	low.executeForm(shrub);
	mid.executeForm(robot);
	boss.executeForm(pardon);

	std::cout << "\n--- Test 2: weak bureaucrat tries to sign ---" << std::endl;

	low.signForm(shrub);
	low.signForm(robot);
	low.signForm(pardon);

	std::cout << "\n--- Test 3: strong bureaucrat signs forms ---" << std::endl;

	boss.signForm(shrub);
	boss.signForm(robot);
	boss.signForm(pardon);

	std::cout << "\n--- Test 4: weak/mid bureaucrats try to execute signed forms ---" << std::endl;

	low.executeForm(shrub);
	mid.executeForm(robot);
	mid.executeForm(pardon);

	std::cout << "\n--- Test 5: boss executes all forms ---" << std::endl;

	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(pardon);

	return 0;
}
 */

void testWork(Bureaucrat *b1, AForm *f1)
{
	std::cout << "=============== Test Work ===============" << std::endl;
	b1->executeForm(*f1);
}

void testNotSigned(Bureaucrat *b1, AForm *f1)
{
	std::cout << "=============== Test NotSigned ===============" << std::endl;
	b1->executeForm(*f1);
}

void testNotEnoughGrade(Bureaucrat *b1, AForm *f1)
{
	std::cout << "=============== Test NotEnoughGrade ===============" << std::endl;
	b1->executeForm(*f1);
}

int main(void)
{
	try
	{
		Bureaucrat *b1 = new Bureaucrat("b1", 5);
		Bureaucrat *b2 = new Bureaucrat("b2", 140);

		ShrubberyCreationForm *f1 = new ShrubberyCreationForm("target 1");

		testNotSigned(b1, f1);
		std::cout << "====> Signing" << std::endl;
		b1->signForm(*f1);
		testNotEnoughGrade(b2, f1);
		testWork(b1, f1);
		delete b1;
		delete b2;
		delete f1;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}