/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:50:32 by nogioni-          #+#    #+#             */
/*   Updated: 2026/06/20 00:43:30 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        const char *str;
        str = static_cast<const char *>(av[1]);
        std::string s(str);
        ScalarConverter::convert(s);
    }
    else
    {
        std::cout << "ERROR:\n"
                    << "You must pass one argument."
                    << std::endl;
        return 1;
    }
    return 0;
}

/*
std::string str;
str = "a";
std::cout << str << std::endl;
ScalarConverter::convert(str);

std::string str1;
str1 = 123;
std::cout << str1 << std::endl;
ScalarConverter::convert(str1);

std::string str2;
str2 = 42.0f;
std::cout << str2 << std::endl;
ScalarConverter::convert(str2);

std::string str3;
str3 = "nanf";
std::cout << str3 << std::endl;
ScalarConverter::convert(str3);

std::string str4;
str4 = "+inf";
std::cout << str4 << std::endl;
ScalarConverter::convert(str4);

std::string str5;
str5 = "hello";
std::cout << str5 << std::endl;
ScalarConverter::convert(str5); */