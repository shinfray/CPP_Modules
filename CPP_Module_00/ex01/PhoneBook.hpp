/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:00:20 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/10 16:32:32 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
# define PHONEBOOK_HPP_

# include "Contact.hpp"

class PhoneBook {
    public:
        static const size_t kPhoneBookCapacity = 8;
    
        PhoneBook();
        PhoneBook(const PhoneBook& src);
        PhoneBook&  operator=(const PhoneBook& rhs);

        ~PhoneBook();

        size_t  get_contacts_count() const;
        void    AddContact();
        void    DisplayContactsList() const;
        void    DisplayContactsDetails() const;

    private:
        std::string TruncateField(const std::string& str) const;

        Contact contacts_[kPhoneBookCapacity];
        size_t  contacts_count_;

};

#endif  // PHONEBOOK_HPP_
