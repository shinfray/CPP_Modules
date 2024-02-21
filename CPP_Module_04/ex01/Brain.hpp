/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:15:14 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 10:35:10 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP_
# define BRAIN_HPP_

# include <string>

class Brain {
    public:
        static int const    kTotalIdeas = 100;

        Brain();
        Brain(const std::string new_ideas[kTotalIdeas]);
        Brain(const Brain& src);
        Brain&  operator=(const Brain& rhs);

        ~Brain();

        void    displayIdeas() const;

    private:
        std::string ideas[kTotalIdeas];
};

#endif  // BRAIN_HPP_
