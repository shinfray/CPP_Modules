/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:13:42 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:28:30 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP_
# define WRONG_ANIMAL_HPP_

# include <string>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(const std::string& new_type);
        WrongAnimal(const WrongAnimal& src);
        WrongAnimal& operator=(const WrongAnimal& rhs);

        virtual ~WrongAnimal();

        const std::string&  getType() const;
        void                setType(const std::string& new_type);
        void                makeSound() const;
        
    protected:
        std::string type;
};

#endif  // WRONG_ANIMAL_HPP_
