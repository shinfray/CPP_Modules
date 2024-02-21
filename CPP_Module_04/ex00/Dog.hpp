/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:37:30 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:28:00 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP_
# define DOG_HPP_

# include <string>

# include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog& src);
        Dog& operator=(const Dog& rhs);

        virtual ~Dog();

        virtual void    makeSound() const;
};

#endif  // DOG_HPP_
