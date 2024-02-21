/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:53:30 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 09:43:02 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP_
# define CONTACT_HPP_

# include <string>

class Contact {
    public:
        enum FieldKey
        {
            kFirstName,
            kLastName,
            kNickname,
            kPhoneNumber,
            kDarkestSecret,
            kFieldKeysNumber
        };

        Contact();
        Contact(const std::string contact_fields[kFieldKeysNumber]);
        Contact(const Contact& src);
        Contact&    operator=(const Contact& rhs);

        ~Contact();

        const std::string&  get_field(const FieldKey field_key) const;
        void                set_field(const std::string& input, const FieldKey field_key);
        void                DisplayFields() const;

    private:
        std::string fields_[kFieldKeysNumber];
};

#endif // CONTACT_HPP_
