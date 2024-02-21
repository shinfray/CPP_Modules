/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:24:09 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:28:14 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP_
# define WRONG_CAT_HPP_

# include <string>

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat& src);
        WrongCat& operator=(const WrongCat& rhs);

        virtual ~WrongCat();

        void    makeSound() const;
};

#endif  // WRONG_CAT_HPP_
