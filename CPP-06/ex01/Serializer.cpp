/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:19:25 by nogioni-          #+#    #+#             */
/*   Updated: 2026/09/07 10:47:25 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer&	Serializer::operator=(const Serializer &other)
{
	(void)other;
	return(*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
	
	uintptr_t	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data	*ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}