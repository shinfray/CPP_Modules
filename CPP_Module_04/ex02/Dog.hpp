/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:37:30 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:39:55 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP_
# define DOG_HPP_

# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const std::string new_ideas[Brain::kTotalIdeas]);
        Dog(const Dog& src);

        virtual ~Dog();

        Dog& operator=(const Dog& rhs);

        virtual void    makeSound() const;
        void            displayIdeas() const;

    private:
        Brain*  dog_brain;
};

#endif  // DOG_HPP_
