/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:22:59 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:11:17 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
# define FIXED_HPP_

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed& src);
        Fixed&  operator=(const Fixed& rhs);

        ~Fixed();

        int     getRawBits() const;
        void    setRawBits(const int raw);

    private:
        static int const kNumberOfFractionalBits_;

        int raw_bits_;
};

#endif  // FIXED_HPP_
