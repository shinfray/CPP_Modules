/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 00:58:26 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:17:35 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP_
# define CLAP_TRAP_HPP_

# include <string>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& src);
        ClapTrap&   operator=(const ClapTrap& rhs);

        ~ClapTrap();

        const std::string&  getName() const;
        unsigned int        getHitPoints() const;
        unsigned int        getMaxHitPoints() const;
        unsigned int        getEnergyPoints() const;
        unsigned int        getAttackDamage() const;
        void                setName(const std::string& name);
        void                setHitPoints(const unsigned int hit_points);
        void                setMaxHitPoints(const unsigned int hit_points);
        void                setEnergyPoints(const unsigned int energy_points);
        void                setAttackDamage(const unsigned int attack_damage);
        void                displayStats() const;
        void                attack(const std::string& target);
        void                takeDamage(unsigned int amount);
        void                beRepaired(unsigned int amount);

    private:
        std::string         name_;
        unsigned int        hit_points_;
        unsigned int        max_hit_points_;
        unsigned int        energy_points_;
        unsigned int        attack_damage_;
};

#endif  // CLAP_TRAP_HPP_
