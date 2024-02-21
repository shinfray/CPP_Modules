/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:13:42 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:34:30 by shinfray         ###   ########.fr       */
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
        Animal& operator=(const Animal& rhs);

        virtual ~Animal();

        const std::string&  getType() const;
        void                setType(const std::string& new_type);
        virtual void        makeSound() const;
        
    protected:
        std::string type;
};

#endif  // ANIMAL_HPP_
