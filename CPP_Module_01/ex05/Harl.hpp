/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:04:01 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/12 14:29:38 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP_
# define HARL_HPP_

# include <string>

class Harl {
    public:
        Harl();

        ~Harl();

        void    complain(std::string level);

    private:
        enum LevelsKey
        {
            kDebug,
            kInfo,
            kWarning,
            kError,
            kLevelKeysNumber
        };

        void    debug();
        void    info();
        void    warning();
        void    error();

        std::string levels_strings_[kLevelKeysNumber];
        void        (Harl::*function_[kLevelKeysNumber])();
};

#endif  // HARL_HPP_
