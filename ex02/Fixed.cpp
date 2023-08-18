/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:13:21 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/07/20 16:37:29 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int ft_pow(int number, int exponent)
{
    if (exponent < 0)
        return 0;
    int result = 1;
    while (exponent > 0)
    {
        result *= number;
        exponent--;
    }
    return (result);
}

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = cpy;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->value = fixed.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

Fixed::Fixed(const int number)
{
    // std::cout << "Int constructor called" << std::endl;
    this->value = number * ft_pow(2, 8);
}

Fixed::Fixed(const float number)
{
    // std::cout << "Float constructor called" << std::endl;
    this->value = std::roundf(number * ft_pow(2, 8));
}

int Fixed::toInt(void) const
{
    int ret;

    ret = this->value / ft_pow(2, 8);
    return (ret);
}

float Fixed::toFloat(void) const
{
    float ret;

    ret = ((float)(this->value)) / ft_pow(2, 8);
    return (ret);
}

std::ostream &operator<<(std::ostream &outStream, const Fixed &number)
{
    outStream << number.toFloat();
    return (outStream);
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->value > fixed.value);
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->value < fixed.value);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->value >= fixed.value);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->value <= fixed.value);
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->value == fixed.value);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->value != fixed.value);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed result;
    result.value = this->value + fixed.value;
    return (result);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed result;
    result.value = this->value - fixed.value;
    return (result);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed result(this->toFloat() * fixed.toFloat());
    return (result);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed result(this->toFloat() / fixed.toFloat());
    return (result);
}

Fixed Fixed::operator++(void)
{
    this->value += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    this->value += 1;
    return (old);
}

Fixed Fixed::operator--(void)
{
    this->value -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    this->value -= 1;
    return (old);
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
    if (first < second)
        return (first);
    else
        return (second);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
    if (first < second)
        return (first);
    else
        return (second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
    if (first > second)
        return (first);
    else
        return (second);
}
const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
    if (first > second)
        return (first);
    else
        return (second);
}

