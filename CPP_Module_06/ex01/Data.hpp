/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:50:03 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/25 18:50:04 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP_
# define DATA_HPP_

# include <iostream>
# include <string>

class Data {
    public:
        Data();
        Data(int val_int, char val_char, std::string val_string);
        Data(const Data& src);
        Data&   operator=(const Data& rhs);

        ~Data();

        int                 get_val_int() const;
        char                get_val_char() const;
        const std::string&  get_val_string() const;

    private:
        int         val_int_;
        char        val_char_;
        std::string val_string_;
};

std::ostream&   operator<<(std::ostream& o, const Data& rhs);

#endif  // DATA_HPP_
