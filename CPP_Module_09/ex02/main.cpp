/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:34:44 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/10 01:12:37by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
        return 0;
    try
    {
        PmergeMe::CheckInput(argc, argv);
        std::vector<int>    vector;
        std::list<int>      list;
        PmergeMe::TimerMergeInsertion< std::vector<int> >(vector, argc, argv, "std::vector");
        PmergeMe::TimerMergeInsertion< std::list<int> >(list, argc, argv, "std::list");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
