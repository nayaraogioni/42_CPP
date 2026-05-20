/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:27:36 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/20 18:57:03 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form parameterized constructor called." << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form copy constructor called." << std::endl;
}

Form &Form::operator=(const Form &other)
{
    std::cout << "Form assignment operator called." << std::endl;
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

Form::~Form()
{
    std::cout << "Form default destructor called." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &b)
{
    os << b.getName() << " Form. Signed: " << b.getSign()
       << ". Grade to sign: " << b.getGradeToSign()
       << ". Grade to execute: " << b.getGradeToExecute();
    return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form's grade is too high!";
}
const char *Form::GradeTooLowException::what() const throw()
{
    return "Form's grade is too low!";
}


const std::string &Form::getName() const
{
    return (_name);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (_gradeToExecute);
}

bool    Form::getSign() const
{
    return (_isSigned);
}

void    Form::beSigned(const Bureaucrat& other)
{
	int bGrade;
    bGrade = other.getGrade();
    if (bGrade <= this->_gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}
