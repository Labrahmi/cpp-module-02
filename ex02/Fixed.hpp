/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:12:13 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/07/20 16:44:28 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int fractional_bits = 8;

public:
    Fixed();
    Fixed(const Fixed &cpy);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed& operator=(const Fixed &fixed);
    Fixed(const int number);
    Fixed(const float number);
    float toFloat(void) const;
    int toInt(void) const;
    // 
    bool operator>(const Fixed &fixed) const;
    bool operator<(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;
    // 
    Fixed operator+(const Fixed &fixed) const;
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;
    // 
    Fixed operator++(void);
    Fixed operator--(void);
    Fixed operator++(int value);
    Fixed operator--(int value);
    // 
    static Fixed& min(Fixed& first, Fixed& second);
    static const Fixed& min(const Fixed& first, const Fixed& second);
    static Fixed& max(Fixed& first, Fixed& second);
    static const Fixed& max(const Fixed& first, const Fixed& second);
};

std::ostream& operator<<(std::ostream &outStream, const Fixed &number);
