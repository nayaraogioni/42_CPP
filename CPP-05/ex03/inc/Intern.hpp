/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:36:35 by nogioni-          #+#    #+#             */
/*   Updated: 2026/05/20 19:06:50 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm*    makeForm(const std::string& formName, const std::string& target);
};

#endif