/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:51:52 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/27 15:31:53by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Span.hpp"

int main()
{
    std::cout << "++++++++++ span n1 ++++++++++" << std::endl << std::endl;
    {
        Span    new_span(5);

        try
        {
            std::cout << "[ NO PROBLEMS ]" << std::endl;
            new_span.addNumber(-5);
            new_span.addNumber(10);
            new_span.addNumber(15);
            new_span.addNumber(7);
            new_span.addNumber(17);
            std::cout << "max n: " << new_span.get_max_n() << std::endl;
            std::cout << "size: " << new_span.get_size() << std::endl;
            int shortest_span = new_span.shortestSpan();
            int longest_span = new_span.longestSpan();
            std::cout << "shortest span: " << shortest_span << std::endl;
            std::cout << "longest span: " << longest_span << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            std::cout << "[ ADD TO MUCH NUMBERS ]" << std::endl;
            new_span.addNumber(18);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;
    }
    std::cout << "++++++++++ span n2 ++++++++++" << std::endl << std::endl;
    {
        Span    new_span(5);

        try
        {
            std::cout << "[ 0 NUMBER ]" << std::endl;
            std::cout << "max n: " << new_span.get_max_n() << std::endl;
            std::cout << "size: " << new_span.get_size() << std::endl;
            int shortest_span = new_span.shortestSpan();
            int longest_span = new_span.longestSpan();
            std::cout << "shortest span: " << shortest_span << std::endl;
            std::cout << "longest span: " << longest_span << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            std::cout << "[ 1 NUMBER ]" << std::endl;
            new_span.addNumber(18);
            std::cout << "max n: " << new_span.get_max_n() << std::endl;
            std::cout << "size: " << new_span.get_size() << std::endl;
            int shortest_span = new_span.shortestSpan();
            int longest_span = new_span.longestSpan();
            std::cout << "shortest span: " << shortest_span << std::endl;
            std::cout << "longest span: " << longest_span << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;
    }
    std::cout << "++++++++++ span n3 ++++++++++" << std::endl << std::endl;
    {
        std::cout << "[ TEST WITH 200000 NUMBERS ]" << std::endl;
        unsigned int    size_vector = 200000;
        srand(time(NULL));
        Span    new_span(size_vector);
        for (unsigned int i = 0; i < size_vector; ++i)
            new_span.addNumber(rand());
        std::cout << "max n: " << new_span.get_max_n() << std::endl;
        std::cout << "size: " << new_span.get_size() << std::endl;
        int shortest_span = new_span.shortestSpan();
        int longest_span = new_span.longestSpan();
        std::cout << "shortest span: " << shortest_span << std::endl;
        std::cout << "longest span: " << longest_span << std::endl;
    }
    std::cout << "++++++++++ span n4 ++++++++++" << std::endl << std::endl;
    {
        std::cout << "[ COPY RANGE OF NUMBERS ]" << std::endl;
        std::vector<int>    base;
        unsigned int        size = 10;
        Span                dest(size);
        for (unsigned int i = 0; i < size; ++i)
            base.push_back(rand() % 20);
        for (std::vector<int>::const_iterator it = base.cbegin(); it != base.cend(); ++it)
            std::cout << "base value: " << *it << std::endl;
        dest.addRangeNumber(base.begin(), base.end());
        dest.display();
    }

    return 0;
}
