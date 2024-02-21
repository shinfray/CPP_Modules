/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:22:45 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:11:31 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

const int   Fixed::kNumberOfFractionalBits_ = 8;

Fixed::Fixed() : raw_bits_(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed&  Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->setRawBits(rhs.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return raw_bits_;
}

void    Fixed::setRawBits(const int raw)
{
    raw_bits_ = raw;
}
