/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:53:03 by nogioni-          #+#    #+#             */
/*   Updated: 2026/03/03 19:10:12 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat assignment operator called." << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat default destructor called." << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int		Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incGrade(int new_grade)
{
	
}
