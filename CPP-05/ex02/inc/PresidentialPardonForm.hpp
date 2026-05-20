/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:51:00 by nayaraogion       #+#    #+#             */
/*   Updated: 2026/05/20 19:02:59 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
		std::string	_target;

	protected:
		virtual void performAction() const;

	public:
		PresidentialPardonForm(); // default constructor
		PresidentialPardonForm(const PresidentialPardonForm& other); // copy constructor
		PresidentialPardonForm(std::string target); // param. constructor
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other); // assign op.
		virtual ~PresidentialPardonForm(); // default destructor
};

#endif