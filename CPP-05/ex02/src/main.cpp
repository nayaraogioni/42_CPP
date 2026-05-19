/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:58:41 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/19 18:42:01 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
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

/* 	std::cout << "\n--- Test 6: Robotomy 10 attempts ---" << std::endl;

	RobotomyRequestForm roboTest("Robot Tomy");
	boss.signForm(roboTest);

	for (int i = 1; i <= 10; i++)
	{
		std::cout << "Attempt " << i << ": ";
		boss.executeForm(roboTest);
	} */

	return 0;
}
