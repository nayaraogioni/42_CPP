/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 11:03:10 by nogioni-          #+#    #+#             */
/*   Updated: 2026/08/18 12:21:52 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SEARILIATION_HPP

class	Serialization
{
	private:
		virtual unsigned int*	serialize(void* ptr) = 0;
		void*	deserialize(unsigned int* raw);
};

typedef	struct s_data
{
	
}	

#endif