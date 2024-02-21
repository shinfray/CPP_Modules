/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:34:11 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/16 13:25:08 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <string>

class Zombie {
    public:
        Zombie(const std::string& name);

        ~Zombie();

        const std::string&  get_name() const;
        void                announce() const;

    private:
        const std::string   name_;
};

#endif  // ZOMBIE_HPP_
