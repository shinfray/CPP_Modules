/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:56:52 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 09:50:41 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <iostream>

Contact::Contact()
{
}

Contact::Contact(const std::string contact_fields[kFieldKeysNumber])
{
    for (FieldKey field_key(kFirstName); field_key < kFieldKeysNumber; field_key = (FieldKey)(field_key + 1))
        set_field(contact_fields[field_key], field_key);
}

Contact::Contact(const Contact& src)
{
    *this = src;
}
Contact&    Contact::operator=(const Contact& rhs)
{
    if (this != &rhs) {
        for (FieldKey field_key(kFirstName); field_key < kFieldKeysNumber; field_key = (FieldKey)(field_key + 1))
            this->set_field(rhs.get_field(field_key), field_key);
    }
    return *this;
}

Contact::~Contact()
{
}

const std::string&  Contact::get_field(const FieldKey field_key) const
{
    return fields_[field_key];
}

void    Contact::set_field(const std::string& input, const FieldKey field_key)
{
    fields_[field_key] = input;
}

void    Contact::DisplayFields() const
{
    std::string messages[5] = {"First Name: ",
                               "Last Name: ",
                               "Nickname: ",
                               "Phone Number: ",
                               "Darkest Secret: "};

    for (FieldKey field_key(kFirstName); field_key < kFieldKeysNumber; field_key = (FieldKey)(field_key + 1))
        std::cout << messages[field_key] << get_field(field_key) << std::endl;
}
