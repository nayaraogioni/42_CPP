/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:58:41 by nogioni-          #+#    #+#             */
/*   Updated: 2026/03/26 17:41:11 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void correctTest(Bureaucrat *b1)
{
	std::cout << "\n=============== Tests supposed to work ===============" << std::endl;
	try
	{
		Form *f1 = new Form("form1", 100, 5);
		Form *f2 = new Form("form2", 5, 5);

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
		Form *f1 = new Form("form2", 1, 5);

		b1->signForm(*f1);
		delete f1;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void formAlreadySigned(Bureaucrat *b1)
{
	std::cout << "\n=============== Already signed ===============" << std::endl;
	try
	{
		Form *f1 = new Form("form2", 140, 5);

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
	try
	{
		Bureaucrat *b1 = new Bureaucrat("b1", 5);

		std::cout << "b1 created: " << *b1 << std::endl;

		correctTest(b1);
		gradeTooLowTest(b1);
		formAlreadySigned(b1);
		delete b1;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}