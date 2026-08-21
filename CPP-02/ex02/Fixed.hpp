/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:46:14 by nogioni-          #+#    #+#             */
/*   Updated: 2026/08/20 17:04:58 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int		_fixedPointValue;
		static const int	_fracBits = 8;

	public:
		Fixed(); // Default constructor
		Fixed(const Fixed& other); // Copy constructor
		Fixed(int const intValue); // Constructor that takes an integer value and converts it to fixed-point
		Fixed(float const floatValue); // Constructor that takes a floating-point value and converts it
		
		~Fixed(); // Destructor

		Fixed& operator=(const Fixed& other); // Copy assignment operator

		float	toFloat(void) const; // Converts the fixed-point value to a floating-point number
		int		toInt(void) const; // Converts the fixed-point value to an integer
		int		getRawBits(void) const; // Returns the raw value of the fixed-point number
		void	setRawBits(int const raw); // Sets the raw value of the fixed-point number

		// COMPARISON OPERATORS
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// ARITHMETIC OPERATORS
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// INCREMENT/DECREMENT OPERATORS
		Fixed& operator++();    // pré-incremento  (++a)
		Fixed  operator++(int); // pós-incremento  (a++)
		Fixed& operator--();    // pré-decremento  (--a)
		Fixed  operator--(int); // pós-decremento  (a--)

		// MIN/MAX FUNCTIONS
		static Fixed&       min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed&       max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};

// Overloads the insertion operator to output the fixed-point value as a floating-point number
std::ostream& operator<<(std::ostream& os, const Fixed& fixed); 

#endif