/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:51:57 by nogioni-          #+#    #+#             */
/*   Updated: 2026/06/27 15:25:07 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <sstream>
#include <ostream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <cerrno>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool	isChar(const std::string& str)
{
	return (str.length() == 1 && !std::isdigit(str[0]));
}

bool	isInt(const std::string& str)
{
	size_t	i = 0;
	errno = 0;

	if (str.empty())
		return false;

	long value = std::strtol(str.c_str(), NULL, 10);
	
	if (errno != 0)
		return false;
	
	if (value < INT_MIN || value > INT_MAX)
		return false;

	if (str[i] == '+' || str[i] == '-')
		i++;

	if (i == str.length())
		return false;

	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}

	return true;
}

bool isFloat(const std::string &str)
{
	errno = 0;

	if (str.empty())
		return false;

	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;

	char *end;

	std::strtod(str.c_str(), &end);

	if (errno != 0)
		return false;

	return (*end == 'f' && *(end + 1) == '\0' && str.find('.') != std::string::npos);
}

bool isDouble(const std::string &str)
{
	errno = 0;

	if (str.empty())
		return false;

	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;

	char *end;

	std::strtod(str.c_str(), &end);

	if (errno != 0)
		return false;

	return (*end == '\0' && str.find('.') != std::string::npos);
}

void	convertChar(const std::string& value)
{
	char c = value[0];
	int n = static_cast<int>(c);

	if (n < 32 || n > 126)
		std::cout << "char: Non displayable." << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;

	std::cout << "int: " << n << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void convertInt(const std::string &value)
{
	long n = strtol(value.c_str(), NULL, 10);

	if (n < 32 || n > 126)
	{
		if (n < -128 || n > 127)
			std::cout << "char: impossible." << std::endl;
		else
			std::cout << "char: Non displayable." << std::endl;
	}
	else
		std::cout << "char: " << "'" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}
void convertFloat(const std::string &value)
{
	double n = strtod(value.c_str(), NULL);

	std::string	c_char;
	std::string	i_int;

	bool pseudo = (value == "nanf" || value == "+inff" || value == "-inff");
	if (pseudo || (n < -128 || n > 127))
	{
		c_char = "impossible.";
		std::cout << "char: " << c_char << std::endl;
	}
	else
	{
		if (n < 32 || n > 126)
			std::cout << "char: Non displayable." << std::endl;
		else
		{
			std::ostringstream oss;
			oss << "'" << static_cast<char>(n) << "'";
			c_char = oss.str();
			std::cout << "char: " << c_char << std::endl;
		}
	}
	if (pseudo || (n < INT_MIN || n > INT_MAX))
		i_int = "impossible.";
	else
	{
		std::ostringstream oss;
		oss << static_cast<int>(n);
		i_int = oss.str();
	}

	std::cout << "int: " << i_int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void convertDouble(const std::string &value)
{
	double n = strtod(value.c_str(), NULL);

	std::string c_char;
	std::string i_int;

	bool pseudo = (value == "nan" || value == "+inf" || value == "-inf");
	if (pseudo || (n < -128 || n > 127))
	{
		c_char = "impossible.";
		std::cout << "char: " << c_char << std::endl;
	}
	else
	{
		if (n < 32 || n > 126)
			std::cout << "char: Non displayable." << std::endl;
		else
		{
			std::ostringstream oss;
			oss << "'" << static_cast<char>(n) << "'";
			c_char = oss.str();
			std::cout << "char: " << c_char << std::endl;
		}
	}
	if (pseudo || (n < INT_MIN || n > INT_MAX))
		i_int = "impossible.";
	else
	{
		std::ostringstream oss;
		oss << static_cast<int>(n);
		i_int = oss.str();
	}

	std::cout << "int: " << i_int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void handleInvalid(void)
{
	std::cout << "char: impossible." << std::endl;
	std::cout << "int: impossible." << std::endl;
	std::cout << "float: impossible." << std::endl;
	std::cout << "double: impossible." << std::endl;
}

void ScalarConverter::convert(const std::string &value)
{
	if (isChar(value))
		return (convertChar(value));
	if (isInt(value))
		return (convertInt(value));
	if (isFloat(value))
		return (convertFloat(value));
	if (isDouble(value))
		return (convertDouble(value));
	return (handleInvalid());
}
