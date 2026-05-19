/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:58:41 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/19 19:29:27 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << " ========== TESTING LOW GRADE AND DECREASE FUNCTION ========== " << std::endl;
		Bureaucrat a("Ana", 149);
		std::cout << a << std::endl;

		a.decGrade(); // goes to 150
		std::cout << a << std::endl;

		a.decGrade(); // tries to decrease to 151
		std::cout << a << std::endl; // ERROR
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << std::endl;
		std::cout << " ========== TESTING HIGH GRADE AND INCREASE FUNCTION ========== " << std::endl;

		Bureaucrat b("John", 3);
		std::cout << b << std::endl;

		b.incGrade(); // goes to 2
		std::cout << b << std::endl;

		b.incGrade(); // goes to 1
		std::cout << b << std::endl;

		b.incGrade();				 // tries to increase 1 one more -> ERROR
		std::cout << b << std::endl; // this wont execute
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "< ========== TESTING INVALID BUREAUCRATS ========== >" << std::endl;
	try
	{
		Bureaucrat x("Invalid", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat y("Invalid", 151);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;

/* 	std::cout << "< ========== TESTING CONSTRUCTORS ========== >" << std::endl;

	Bureaucrat Z("Z", 35);
	std::cout << Z << std::endl;
	Bureaucrat Y("Y", 21);
	std::cout << Y << std::endl;
	Bureaucrat W(Y);
	std::cout << W << std::endl;

	std::cout << "Z = Y" << std::endl;
	Z = Y;
	std::cout << Z << std::endl; */

	return 0;
}