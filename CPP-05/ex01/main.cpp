/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:58:41 by nogioni-          #+#    #+#             */
/*   Updated: 2026/03/20 16:12:06 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("John", 2);
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

	return 0;
}