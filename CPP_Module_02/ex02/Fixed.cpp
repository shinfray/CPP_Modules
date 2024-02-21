/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:22:45 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:13:03 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

const int   Fixed::kNumberOfFractionalBits_ = 8;

Fixed::Fixed() : raw_bits_(0)
{
}

Fixed::Fixed(const int value)
    : raw_bits_(value << kNumberOfFractionalBits_)
{
}

Fixed::Fixed(const float value)
    : raw_bits_((int)(roundf(value * (1 << kNumberOfFractionalBits_))))
{
}

Fixed::Fixed(const Fixed& src)
{
    *this = src;
}

Fixed&  Fixed::operator=(const Fixed& rhs)
{
    if (this != &rhs)
        this->setRawBits(rhs.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
}

bool    Fixed::operator>(const Fixed& rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool    Fixed::operator<(const Fixed& rhs) const
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool    Fixed::operator>=(const Fixed& rhs) const
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool    Fixed::operator<=(const Fixed& rhs) const
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool    Fixed::operator==(const Fixed& rhs) const
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool    Fixed::operator!=(const Fixed& rhs) const
{
    return (this->getRawBits() != rhs.getRawBits());
}

Fixed   Fixed::operator+(const Fixed& rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed   Fixed::operator-(const Fixed& rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed   Fixed::operator*(const Fixed& rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed   Fixed::operator/(const Fixed& rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed&  Fixed::operator++()
{
    ++raw_bits_;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed   temp(*this);

	++raw_bits_;
    return temp;
}

Fixed&  Fixed::operator--()
{
    --raw_bits_;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed   temp(*this);

    --raw_bits_;
    return temp;
}

int Fixed::getRawBits() const
{
    return raw_bits_;
}

void    Fixed::setRawBits(const int raw)
{
    raw_bits_ = raw;
}

float   Fixed::toFloat() const
{
    return ((float)getRawBits() / (float)(1 << kNumberOfFractionalBits_));
}

int Fixed::toInt() const
{
    return (getRawBits() >> kNumberOfFractionalBits_);
}

Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() <= b.getRawBits())
        return a;
    return b;
}

const Fixed&    Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() <= b.getRawBits())
        return a;
    return b;
}

Fixed&  Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() >= b.getRawBits())
        return a;
    return b;
}

const Fixed&    Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() >= b.getRawBits())
        return a;
    return b;
}

std::ostream&   operator<<(std::ostream& o, const Fixed& rhs)
{
    return o << rhs.toFloat();
}
