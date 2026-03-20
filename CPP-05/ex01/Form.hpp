/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:10:02 by nogioni-          #+#    #+#             */
/*   Updated: 2026/03/20 19:36:09 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Form
{
    private:
        const std::string   _name;
        bool                _sign;
        const int           _grade;
    public:
        Form();
        Form(const Form& other);
        Form &operator=(const Form &other);
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
        int getFormGrade() const;
        void incGrade(void); 
        void decGrade(void);
        beSigned(Bureaucrat )
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif