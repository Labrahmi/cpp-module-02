/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:12:13 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/07/19 13:23:52 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
    int value;
    static const int fractional_bits = 8;
    
public:
    Fixed();
    Fixed(const Fixed &cpy);
    ~Fixed();

    Fixed& operator=(const Fixed &fixed);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
