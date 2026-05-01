/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:10:02 by nogioni-          #+#    #+#             */
/*   Updated: 2026/04/30 19:35:22 by nogioni-         ###   ########.fr       */
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
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        ~Form();

        class   GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Form grade is too high!";
                }
        };

        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char *what() const throw()
            {
                return "Form grade is too low!";
            }
        };

        const std::string &getName() const;
        int getFormGradeToSign() const;
        int getFormGradeToExecute() const;
        bool getSign() const;

        void beSigned(const Bureaucrat &other); // changes the form's status to signed if the grade is high enough (>= to the required one)
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif