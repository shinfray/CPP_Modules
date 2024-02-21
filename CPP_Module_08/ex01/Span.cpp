/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:53:22 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/29 15:08:46by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>

Span::Span(unsigned int N) : max_n_(N)
{
}

Span::Span(const Span& src)
{
    *this = src;
}

Span&   Span::operator=(const Span& rhs)
{
    if (this != &rhs) {
        max_n_ = rhs.get_max_n();
        vector_ = rhs.vector_;
    }
    return *this;
}

const int&  Span::operator[](unsigned int index)
{
    return vector_.at(index);
}

Span::~Span()
{
}

unsigned int    Span::get_max_n() const
{
    return max_n_;
}

unsigned int    Span::get_size() const
{
    return vector_.size();
}

void    Span::addNumber(int number)
{
    if (get_size() == get_max_n())
        throw MaxSizeReachedException();
    vector_.push_back(number);
}
void    Span::addRangeNumber(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
    if (get_size() + std::distance(first, last) > get_max_n())
        throw NotEnoughSpaceAvailableException();
    vector_.insert(vector_.end(), first, last);
}

int     Span::longestSpan() const
{
    if (get_size() < 2)
        throw NotEnoughNumbersForSpanException();
    int min_element = *std::min_element(vector_.begin(), vector_.end());
    int max_element = *std::max_element(vector_.begin(), vector_.end());
    std::cout << "max_element: " << max_element << std::endl;
    std::cout << "min_element: " << min_element << std::endl;
    return (max_element - min_element);
}

int     Span::shortestSpan() const
{
    if (get_size() < 2)
        throw NotEnoughNumbersForSpanException();

    std::vector<int>    copy(vector_);
    std::sort(copy.begin(), copy.end());
    std::vector<int>::const_iterator        it = copy.begin();
    const std::vector<int>::const_iterator  ite = copy.end();
    int smallest_span = *(it + 1) - *it;
    int tmp;
    int min_value_short_span = *it;
    int max_value_short_span = *(it + 1);
    for (; it + 1 != ite; ++it) {
        tmp = *(it + 1) - *it;
        if (tmp < smallest_span) {
            min_value_short_span = *it;
            max_value_short_span = *(it + 1);
            smallest_span = tmp;
        }
    }
    std::cout << "max_value_short_span: " << max_value_short_span << std::endl;
    std::cout << "min_value_short_span: " << min_value_short_span << std::endl;
    return smallest_span;
}

void    Span::display() const
{
    std::vector<int>::const_iterator    ite = vector_.end();
    std::cout << "[ Span values ]" << std::endl;
    for (std::vector<int>::const_iterator it = vector_.begin(); it != ite; ++it)
        std::cout << *it << std::endl;
}
