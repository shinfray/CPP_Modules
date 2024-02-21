/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:52:59 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/27 15:13:09y shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP_
# define SPAN_HPP_

# include <exception>
# include <vector>

class Span {
    public:
        Span(unsigned int N);
        Span(const Span& src);
        Span&   operator=(const Span& rhs);

        const int&  operator[](unsigned int index);

        ~Span();

        unsigned int    get_max_n() const;
        unsigned int    get_size() const;

        void    addNumber(int number);
        void    addRangeNumber(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);
        int     longestSpan() const;
        int     shortestSpan() const;
        void    display() const;

        class MaxSizeReachedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Max size reached exception";
                }
        };
        class NotEnoughSpaceAvailableException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Not enough space available exception";
                }
        };
        class NotEnoughNumbersForSpanException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Not enough numbers for span exception";
                }
        };
        
    private:
        Span();

        std::vector<int>    vector_;
        unsigned int        max_n_;
};

#endif  // SPAN_HPP_
