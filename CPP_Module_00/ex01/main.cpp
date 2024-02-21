/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:57:30 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/05 13:08:17by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   phone_book;
    std::string temp;

    do
    {
        std::cout << "Commands availble: ADD, SEARCH, EXIT" << std::endl;
        std::cout << "Enter a command: ";
        std::getline(std::cin, temp);
        if (std::cin.good() == true && temp == "ADD") {
            phone_book.AddContact();
        } else if (std::cin.good() == true && temp == "SEARCH") {
            phone_book.DisplayContactsList();
            if (phone_book.get_contacts_count() > 0)
                phone_book.DisplayContactsDetails();
        }
    } while (std::cin.good() == true && temp != "EXIT");
    if (std::cin.eof() == true)
        std::cout << std::endl;
    return 0;
}
