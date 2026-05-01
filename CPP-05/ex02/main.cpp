/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayaraogioni <nayaraogioni@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:58:41 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/01 15:35:51 by nayaraogion      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>


void correctTest(Bureaucrat *b1)
{
	std::cout << "\n=============== Tests supposed to work ===============" << std::endl;
	try
	{
		AForm *f1 = new AForm("AForm1", 100, 5);
		AForm *f2 = new AForm("AForm2", 5, 5);

		b1->signForm(*f1);
		b1->signForm(*f2);
		delete f1;
		delete f2;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void gradeTooLowTest(Bureaucrat *b1)
{
	std::cout << "\n=============== Tests grade too low ===============" << std::endl;
	try
	{
		AForm *f1 = new AForm("AForm2", 1, 5);

		b1->signForm(*f1);
		delete f1;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void AFormAlreadySigned(Bureaucrat *b1)
{
	std::cout << "\n=============== Already signed ===============" << std::endl;
	try
	{
		AForm *f1 = new AForm("AForm2", 140, 5);

		b1->signForm(*f1);
		b1->signForm(*f1);
		delete f1;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	std::srand(std::time(NULL));
	try
	{
		Bureaucrat *b1 = new Bureaucrat("b1", 5);

		std::cout << "b1 created: " << *b1 << std::endl;

		correctTest(b1);
		gradeTooLowTest(b1);
		AFormAlreadySigned(b1);
		delete b1;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}