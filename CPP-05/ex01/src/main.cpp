/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:58:41 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/19 17:23:18 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{

		std::cout << "< ========== TESTING CORRECT GRADE TO SIGN ========== >" << std::endl;
		Bureaucrat b("John", 74);
		std::cout << b << std::endl;

		Form a("Registration", 74, 75);
		std::cout << a << std::endl;

		b.signForm(a);
		std::cout << a << std::endl;

		std::cout << std::endl;

		std::cout << "< ========== TESTING INCORRECT GRADE TO SIGN ========== >" << std::endl;

		Bureaucrat c("Ross", 75);
		std::cout << c << std::endl;

		Form d("Subscription", 74, 75);
		std::cout << d << std::endl;

		c.signForm(d);
		std::cout << d << std::endl;

		std::cout << std::endl;

		std::cout << "< ========== TESTING INVALID FORM ========== >" << std::endl;
		try
		{
			Form x("Invalid", 0, 10);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl;

		return 0;
}
