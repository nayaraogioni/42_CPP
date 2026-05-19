/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:53:03 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/19 14:01:06 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(std::string bName, int bGrade) : _name(bName)
{
    std::cout << "Bureaucrat parameterized constructor called." << std::endl;
    if (bGrade < 1)
        throw GradeTooHighException();
    if (bGrade > 150)
        throw GradeTooLowException();
    _grade = bGrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignment operator called." << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat default destructor called." << std::endl;
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int		Bureaucrat::getGrade() const
{
	return (_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Bureaucrat::incGrade(void)
{
	if (_grade == 1)
	{
		throw GradeTooHighException();
	}
	else
	{
		std::cout << "<Increasing grade...>" << std::endl;
		_grade -= 1;
	}
}

void Bureaucrat::decGrade(void)
{
	if (_grade == 150)
	{
		throw GradeTooLowException();
	}
	else
	{
		std::cout << "<Decreasing grade...>" << std::endl;
		_grade += 1;
	}
}
