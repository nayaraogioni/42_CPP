/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:04:37 by nogioni-          #+#    #+#             */
/*   Updated: 2026/09/07 14:45:33 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


int	main(void)
{
	//std::srand(std::time(NULL));
	Base *obj[5];

	for (int i = 0; i < 5; i++)
	{
		obj[i] = generate();
		identify(obj[i]);
		identify(*obj[i]);
	}
	
	for (int j = 0; j < 5; j++)
	{
		delete obj[j];
		std::cout << "Deleting object..." << std::endl;
	}
	return (0);
}
