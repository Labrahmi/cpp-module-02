/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:12:13 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/07/20 12:58:00 by ylabrahm         ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream &outStream, const Fixed &number);
