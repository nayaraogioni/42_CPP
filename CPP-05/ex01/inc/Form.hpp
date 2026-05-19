/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayaraogioni <nayaraogioni@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:10:02 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/01 15:27:10 by nayaraogion      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        Form();
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        const std::string &getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool getSign() const;

        void beSigned(const Bureaucrat &other); // changes the form's status to signed if the grade is high enough (>= to the required one)
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif