/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayaraogioni <nayaraogioni@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:34:20 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/01 14:01:25 by nayaraogion      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class   Bureaucrat
{
	private:
		const std::string _name;
		int _grade; // 1 to 150 (1 the highest; 150 the lowest)
	public:
		Bureaucrat();
		Bureaucrat(std::string bName, int bGrade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		class	GradeTooHighException : public std::exception
		{
				public:
					virtual const char*	what() const throw() {
						return "Grade is too high!";
					}
		};

		class   GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too low!";
				}
		};

		const	std::string &getName() const;
		int		getGrade() const;
		void	incGrade(void); // if the grade is 3 and we call this func, the grade will be 2 (1 is the highest)
		void	decGrade(void); // if the grade is 3 and we call this func, the grade will be 4 (150 is the lowest)
		void	signForm(AForm &form); // calls for beSigned to try and sign the form
								   // if the form is signed with success, prints OK
								   // otherwise KO, because <reason> [more info on subject]
		void	executeForm(AForm const &form) const;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif