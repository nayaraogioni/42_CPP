/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:27:36 by nogioni-          #+#    #+#             */
/*   Updated: 2026/03/26 17:12:40 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor called." << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form copy constructor called." << std::endl;
}

Form::~Form()
{
    std::cout << "Form default destructor called." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Form &b)
{
    os << b.getName() << " Form. Signed: " << b.getSign()
       << ". Grade to sign: " << b.getFormGradeToSign()
       << ". Grade to execute: " << b.getFormGradeToExecute();
    return os;
}

const std::string &Form::getName() const
{
    return (_name);
}

int Form::getFormGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getFormGradeToExecute() const
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
