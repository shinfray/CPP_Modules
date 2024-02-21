/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:22:59 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:12:05 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
# define FIXED_HPP_

# include <fstream>

class Fixed {
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& src);
        Fixed&  operator=(const Fixed& rhs);

        ~Fixed();


        int     getRawBits() const;
        void    setRawBits(const int raw);
        float   toFloat() const;
        int     toInt() const;

    private:
        static int const kNumberOfFractionalBits_;

        int raw_bits_;
};

std::ostream&   operator<<(std::ostream& o, const Fixed& rhs);

#endif  // FIXED_HPP_
