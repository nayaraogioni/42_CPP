/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 19:21:15 by nogioni-          #+#    #+#             */
/*   Updated: 2026/09/02 19:57:15 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <limits>
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

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool isChar(const std::string &str)
{
	return (str.length() == 1 && !std::isdigit(str[0]));
}

bool isInt(const std::string &str)
{
	size_t i = 0;
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

void handleInvalid(void)
{
	std::cout << "char: impossible." << std::endl;
	std::cout << "int: impossible." << std::endl;
	std::cout << "float: impossible." << std::endl;
	std::cout << "double: impossible." << std::endl;
}

std::string	toChar(double n, bool pseudo)
{
	if (pseudo || n < -128 || n > 127)
		return "impossible.";

	if (n < 32 || n > 126)
		return "Non displayable.";

	std::ostringstream oss;
	oss << "'" << static_cast<char>(n) << "'";
	return oss.str();
}

std::string	toInt(double n, bool pseudo)
{
	if (pseudo || n < INT_MIN || n > INT_MAX)
		return "impossible.";

	std::ostringstream oss;
	oss << static_cast<int>(n);
	return oss.str();
}

std::string toFloat(double n, bool pseudo, const std::string& value)
{
	if (pseudo)
	{
		if (value == "nan" || value == "nanf")
			return "nanf";
		if (value == "+inf" || value == "+inff")
			return "+inff";
		if (value == "-inf" || value == "-inff")
			return "-inff";
	}
	
	if (n < -std::numeric_limits<float>::max() ||
		n > std::numeric_limits<float>::max())
		return "impossible.";

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1)
		<< static_cast<float>(n) << "f";
	return oss.str();
}

std::string toDouble(double n, bool pseudo, const std::string &value)
{
	if (pseudo)
	{
		if (value == "nan" || value == "nanf")
			return "nan";
		if (value == "+inf" || value == "+inff")
			return "+inf";
		if (value == "-inf" || value == "-inff")
			return "-inf";
	}
	
	if (n < -std::numeric_limits<double>::max() ||
		n > std::numeric_limits<double>::max())
		return "impossible.";

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1)
		<< static_cast<double>(n);
	return oss.str();
}

void	convertChar(const std::string &value)
{
	char c = value[0];
	double n = static_cast<double>(c);

	std::cout << "char: " << toChar(n, false) << std::endl;
	std::cout << "int: " << toInt(n, false) << std::endl;
	std::cout << "float: " << toFloat(n, false, value) << std::endl;
	std::cout << "double: " << toDouble(n, false, value) << std::endl;
}
void	convertInt(const std::string &value)
{
	long raw = std::strtol(value.c_str(), NULL, 10);
	double n = static_cast<double>(raw);

	std::cout << "char: " << toChar(n, false) << std::endl;
	std::cout << "int: " << toInt(n, false) << std::endl;
	std::cout << "float: " << toFloat(n, false, value) << std::endl;
	std::cout << "double: " << toDouble(n, false, value) << std::endl;
}
void	convertFloat(const std::string &value)
{
	double n = std::strtod(value.c_str(), NULL);
	bool pseudo = (value == "nanf" || value == "+inff" || value == "-inff");

	std::cout << "char: " << toChar(n, pseudo) << std::endl;
	std::cout << "int: " << toInt(n, pseudo) << std::endl;
	std::cout << "float: " << toFloat(n, pseudo, value) << std::endl;
	std::cout << "double: " << toDouble(n, pseudo, value) << std::endl;
}

void	convertDouble(const std::string &value)
{
	double n = std::strtod(value.c_str(), NULL);
	bool pseudo = (value == "nan" || value == "+inf" || value == "-inf");

	std::cout << "char: " << toChar(n, pseudo) << std::endl;
	std::cout << "int: " << toInt(n, pseudo) << std::endl;
	std::cout << "float: " << toFloat(n, pseudo, value) << std::endl;
	std::cout << "double: " << toDouble(n, pseudo, value) << std::endl;
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