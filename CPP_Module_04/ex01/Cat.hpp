/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 22:24:09 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:36:09 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP_
# define CAT_HPP_

# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(const std::string new_ideas[Brain::kTotalIdeas]);
        Cat(const Cat& src);
        Cat& operator=(const Cat& rhs);

        virtual ~Cat();

        virtual void    makeSound() const;
        void            displayIdeas() const;

    private:
        Brain*  cat_brain;
};

#endif  // CAT_HPP_
