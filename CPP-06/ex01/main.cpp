/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:29:52 by nogioni-          #+#    #+#             */
/*   Updated: 2026/09/07 11:56:38 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data	obj;
	std::cout << "DATA OBJ CREATED" << std::endl;
	
	obj.value = 10;
	std::cout << "OBJ VALUE: " << obj.value << std::endl;
	std::cout << "OBJ ADDRESS: " << &obj << std::endl;
	
	std::cout << "----------------------------------" << std::endl;
	Data	*original = &obj;
	std::cout << "DATA POINTER CREATED" << std::endl;
	std::cout << "DATA POINTER VALUE: " << original << std::endl;

	std::cout << "----------------------------------" << std::endl;
	uintptr_t raw;
	Data	*recovered;
	std::cout << "UINTPTR_T RAW CREATED" << std::endl;
	std::cout << "DATA RECOVERED CREATED" << std::endl;

	std::cout << "----------------------------------" << std::endl;
	
	raw = Serializer::serialize(original);
	std::cout << "RAW AFTER SERIALIZATION: " << std::hex << raw << std::endl;

	std::cout << std::dec;

	recovered = Serializer::deserialize(raw);
	std::cout << "RECOVERED AFTER DESERIALIZATION: " << recovered << std::endl;
	
	std::cout << "RECOVERED VALUE AFTER DESERIALIZATION: " <<recovered->value << std::endl;
	
	std::cout << "----------------------------------" << std::endl;
	
	if (recovered == original)
		std::cout << "POINTERS MATCH!" << std::endl;
	else
		std::cout << "POINTERS DO NOT MATCH!" << std::endl;

	return (0);
}