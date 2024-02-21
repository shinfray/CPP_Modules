/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 23:22:36 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/15 23:29:35by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain()
{
    std::cout << "Default Brain constructor" << std::endl;
}

Brain::Brain(const std::string new_ideas[kTotalIdeas])
{
    std::cout << "Default Brain parametized constructor" << std::endl;
    for (int i = 0; i < kTotalIdeas; ++i)
        ideas[i] = new_ideas[i];
}

Brain::Brain(const Brain& src)
{
    std::cout << "Default Brain copy constructor" << std::endl;
    *this = src;
}

Brain&  Brain::operator=(const Brain& rhs)
{
    std::cout << "Default Brain copy assignement constructor" << std::endl;
    for (int i = 0; i < kTotalIdeas; ++i)
        ideas[i] = rhs.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "Default Brain destructor" << std::endl;
}

void    Brain::displayIdeas() const
{
    for (int i = 0; i < kTotalIdeas; ++i)
        std::cout << "[" << i + 1 << "] " << ideas[i] << std::endl;
}
