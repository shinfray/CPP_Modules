/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:34:11 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 13:27:04 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <string>

class Zombie {
    public:
        Zombie();
        Zombie(std::string& name);

        ~Zombie();

        const std::string&  get_name() const;
        void                set_name(const std::string& name);
        void                announce() const;

    private:
        std::string name_;
};

#endif  // ZOMBIE_HPP_
