/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:53:03 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/13 15:44:57 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
    std::cout << "Bureaucrat default constructor called." << std::endl;
}

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

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat assignment operator called." << std::endl;
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat default destructor called." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int		Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incGrade(void)
{
    if (_grade == 1)
    {
        throw GradeTooHighException();
    }
    else
        _grade -= 1;
}

void Bureaucrat::decGrade(void)
{
    if (_grade == 150)
    {
        throw GradeTooLowException();
    }
    else
        _grade += 1;
}
void Bureaucrat::signForm(AForm &form)
{
   try
   {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
   }
   catch (const std::exception &e)
   {
       std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
   }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}