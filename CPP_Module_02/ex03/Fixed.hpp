/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:22:59 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:13:28 by shinfray         ###   ########.fr       */
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

        bool    operator>(const Fixed& rhs) const;
        bool    operator<(const Fixed& rhs) const;
        bool    operator>=(const Fixed& rhs) const;
        bool    operator<=(const Fixed& rhs) const;
        bool    operator==(const Fixed& rhs) const;
        bool    operator!=(const Fixed& rhs) const;
        Fixed   operator+(const Fixed& rhs) const;
        Fixed   operator-(const Fixed& rhs) const;
        Fixed   operator*(const Fixed& rhs) const;
        Fixed   operator/(const Fixed& rhs) const;
        Fixed&  operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);

        int     getRawBits() const;
        void    setRawBits(const int raw);
        float   toFloat() const;
        int     toInt() const;

        static Fixed&       min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed&       max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

    private:
        static const int    kNumberOfFractionalBits_;

        int raw_bits_;
};

std::ostream&   operator<<(std::ostream& o, const Fixed& rhs);

#endif  // FIXED_HPP_
