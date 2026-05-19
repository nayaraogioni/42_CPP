/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:27:36 by nogioni-          #+#    #+#             */
/*   Updated: 2026/03/26 17:12:40 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "AForm copy constructor called." << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm default destructor called." << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "AForm assignment operator called." << std::endl;
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &Form)
{
    os << Form.getName() << " AForm. Signed: " << Form.getSign()
       << ". Grade to sign: " << Form.getGradeToSign()
       << ". Grade to execute: " << Form.getGradeToExecute();
    return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high!";
}
const char *AForm::GradeTooLowException::what() const throw()
{
     return "AForm grade is too low!";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "AForm is not signed!";
}

const std::string &AForm::getName() const
{
    return (_name);
}

int AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (_gradeToExecute);
}

bool    AForm::getSign() const
{
    return (_isSigned);
}

void    AForm::beSigned(const Bureaucrat& other)
{
    int bGrade;
    bGrade = other.getGrade();
    if (bGrade <= this->_gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

void    AForm::execute(Bureaucrat const &executor) const
{
    if (!this->_isSigned)
        throw NotSignedException();
    if (this->_gradeToExecute < executor.getGrade())
        throw GradeTooLowException();
    else
        performAction();
}
