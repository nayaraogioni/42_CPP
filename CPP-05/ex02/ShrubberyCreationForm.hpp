/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayaraogioni <nayaraogioni@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:36:23 by nayaraogion       #+#    #+#             */
/*   Updated: 2026/05/01 15:55:03 by nayaraogion      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    protected:
       virtual void    performAction() const;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();
};

#endif