/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:50:00 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/25 18:50:01 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : val_int_(42), val_char_('s'), val_string_("hello world!")
{
}

Data::Data(int val_int, char val_char, std::string val_string)
    : val_int_(val_int), val_char_(val_char), val_string_(val_string)
{
}

Data::Data(const Data& src) 
{
    *this = src;
}

Data&   Data::operator=(const Data& rhs)
{
    if (this != &rhs) {
        this->val_int_ = rhs.get_val_int();
        this->val_char_ = rhs.get_val_char();
        this->val_string_ = rhs.get_val_string();
    }
    return *this;
}

Data::~Data()
{
}

int Data::get_val_int() const
{
    return val_int_;
}

char    Data::get_val_char() const
{
    return val_char_;
}

const std::string&  Data::get_val_string() const
{
    return val_string_;
}

std::ostream&   operator<<(std::ostream& o, const Data& rhs)
{
    return (o << "val_int: " << rhs.get_val_int() << std::endl \
            << "val_char: " << rhs.get_val_char() << std::endl \
            << "val_string: " << rhs.get_val_string());
}
