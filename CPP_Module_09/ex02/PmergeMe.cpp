/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:35:19 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/10 01:17:13by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    PmergeMe::CheckInput(int argc, char** argv)
{
    std::vector<int>    container;
    for (int i = 1; i < argc; ++i) {
        std::istringstream  iss(argv[i]);
        std::string         s(iss.str());
        int n = 0;
        iss >> std::noskipws >> n;
        if (iss.fail() || !iss.eof() || (s[0] == '0' && n != 0))
            throw BadInputException();
        if (n < 0)
            throw NegativeNumbersException();
        if (!std::isdigit(s[0]))
            throw BadInputException();
        container.push_back(n);
    }
    MergeInsertion(container.begin(), container.end());
    // const std::vector<int>::iterator    it_e = container.end();
    // if (std::adjacent_find(container.begin(), it_e) != it_e)
    //         throw DuplicateNumbersException();
    std::cout << "Before:";
    for (int i = 1; i < argc; ++i)
        std::cout << " " << argv[i];
    std::cout << std::endl;
    std::cout << "After:";
    std::for_each(container.begin(), container.end(), &DisplayValues<int>);
    std::cout << std::endl;
}
