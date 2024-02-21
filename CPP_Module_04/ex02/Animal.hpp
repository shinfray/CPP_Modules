/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:13:42 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 11:55:47by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

# include <string>

class Animal {
    public:
        Animal();
        Animal(const std::string& new_type);
        Animal(const Animal& src);

        virtual ~Animal();

        Animal& operator=(const Animal& rhs);

        const std::string&  getType() const;
        void                setType(const std::string& new_type);
        virtual void        makeSound() const = 0;
        virtual void        displayIdeas() const = 0;
        
    protected:
        std::string type;
};

#endif  // ANIMAL_HPP_
