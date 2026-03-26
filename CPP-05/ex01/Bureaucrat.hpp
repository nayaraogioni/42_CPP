/* ************************************************************************** */
/*									    */
/*							:::      ::::::::   */
/*   Bureaucrat.hpp				     :+:      :+:    :+:   */
/*						    +:+ +:+	 +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>	  +#+  +:+       +#+	*/
/*						+#+#+#+#+#+   +#+	   */
/*   Created: 2026/02/24 18:08:19 by nogioni-	  #+#    #+#	     */
/*   Updated: 2026/03/03 18:50:53 by nogioni-	 ###   ########.fr       */
/*									    */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

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

		const std::string &getName() const;
		int		getGrade() const;
		void    incGrade(void); // if the grade is 3 and we call this func, the grade will be 2 (1 is the highest)
		void    decGrade(void); // if the grade is 3 and we call this func, the grade will be 4 (150 is the lowest)
		void signForm(Form &form); // calls for beSigned to try and sign the form
								   // if the form is signed with success, prints OK
								   // otherwise KO, because <reason> [more info on subject]
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif