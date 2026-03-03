/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:08:19 by nogioni-          #+#    #+#             */
/*   Updated: 2026/02/24 18:26:48 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>


class   Bureaucrat
{
    private:
        const std::string _name;
        int _grade; // 1 to 150 (1 the highest; 150 the lowest)
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void    incGrade(int new_grade); // if the grade is 3 and we call this func, the grade will be 2 (1 is the highest)
        void    decGrade(int new_grade); // if the grade is 3 and we call this func, the grade will be 4 (150 is the lowest)
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif