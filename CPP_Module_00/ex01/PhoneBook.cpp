/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:54:29 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:05:13by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook() : contacts_count_(0)
{
}

PhoneBook::PhoneBook(const PhoneBook& src)
{
    *this = src;
}

PhoneBook&  PhoneBook::operator=(const PhoneBook& rhs)
{
    if (this != &rhs) {
        for (size_t i = 0; i < kPhoneBookCapacity; ++i)
            this->contacts_[i] = rhs.contacts_[i];
        this->contacts_count_ = rhs.get_contacts_count();
    }
    return *this;
}

PhoneBook::~PhoneBook()
{
}

size_t  PhoneBook::get_contacts_count() const
{
    return (contacts_count_);
}

void    PhoneBook::AddContact()
{
    const std::string   prompt[Contact::kFieldKeysNumber] = {"First Name: ",
                                                             "Last Name: ",
                                                             "Nickname: ",
                                                             "Phone Number: ",
                                                             "Darkest Secret: "};
    std::string         temp[Contact::kFieldKeysNumber];

    for (Contact::FieldKey field_key(Contact::kFirstName); field_key < Contact::kFieldKeysNumber; field_key = (Contact::FieldKey)(field_key + 1)) {
        do {
            std::cout << prompt[field_key];
            std::getline(std::cin, temp[field_key]);
            if (std::cin.good() == false)
                return;
        } while (temp[field_key].size() < 1);
    }
    if (contacts_count_ >= kPhoneBookCapacity) {
        for (size_t i = 0; i < kPhoneBookCapacity - 1; ++i)
            contacts_[i] = contacts_[i + 1];
        --contacts_count_;
    }
    Contact newContact(temp);
    contacts_[get_contacts_count()] = newContact;
    ++contacts_count_;
}

void    PhoneBook::DisplayContactsList() const
{
    if (contacts_count_ <= 0) {
        std::cout << "There are no contacts in the list!" << std::endl;
        return;
    }
    const std::string   bordure("|-------------------------------------------|");
    std::cout << bordure << std::endl;
    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
    std::cout << bordure << std::endl;
    for (size_t i(0); i < contacts_count_; ++i) {
        std::cout << "|" << std::setw(10) << i << "|";
        for (Contact::FieldKey field_key(Contact::kFirstName);
                field_key <= Contact::kNickname;
                field_key = (Contact::FieldKey)(field_key + 1)) {
            std::cout << std::setw(10) << TruncateField(contacts_[i].get_field(field_key));
            std::cout << "|";
        }
        std::cout << std::endl;
    }
    std::cout << bordure << std::endl;
}

void    PhoneBook::DisplayContactsDetails() const
{
    std::cout << "Enter contact index to see details: ";
    std::string temp;
    std::getline(std::cin, temp);
    if (std::cin.good() == false || temp.empty() == true)
        return;
    size_t  index(0);
    if (isdigit(temp[0]) == true) {
        std::istringstream  iss(temp);
        iss >> std::noskipws >> index;
        if (!iss.fail() && iss.eof() && (temp[0] != '0' || index == 0) && index < contacts_count_) {
            contacts_[index].DisplayFields();
            return;
        }
    }
    std::cout << "Invalid index!" << std::endl;
}

std::string PhoneBook::TruncateField(const std::string& str) const
{
    std::string truncated_str(str, 0, 10);
    if (str.length() > 10)
        truncated_str.replace(9, 1, ".");
    return truncated_str;
}
