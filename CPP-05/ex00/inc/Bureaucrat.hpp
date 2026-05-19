/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:34:06 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/19 13:11:14 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class   Bureaucrat
{
	private:
		const std::string _name;
		int _grade; // 1 to 150 (1 the highest; 150 the lowest)
	public:
		Bureaucrat(); // default constructor
		Bureaucrat(std::string bName, int bGrade); // param. constructor
		Bureaucrat(const Bureaucrat& other); // copy constructor
		Bureaucrat &operator=(const Bureaucrat &other); // assignm. op.
		~Bureaucrat(); // destructor

		// EXCEPTION CLASSES
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		// METHODS
		const	std::string &getName() const;
		int					getGrade() const;

		void	incGrade(void); // if the grade is 3 and we call this the grade will be 2
		void	decGrade(void); // if the grade is 3 and we call this the grade will be 4
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif