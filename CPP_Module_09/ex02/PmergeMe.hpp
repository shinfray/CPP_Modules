/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:35:27 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/09 22:24:34shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP_
# define PMERGE_ME_HPP_

# include <algorithm>
# include <exception>
# include <iostream>
# include <iterator>
# include <list>
# include <sstream>
# include <string>
# include <vector>

#include <sys/time.h>

class PmergeMe {
    public:
        class DuplicateNumbersException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "duplicate numbers";
                }
        };
        class BadInputException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "bad input";
                }
        };
        class NegativeNumbersException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "negative numbers";
                }
        };

        static void CheckInput(int argc, char** argv);

        template<typename Container>
        static void TimerMergeInsertion(Container& container, int argc, char** argv, const std::string& type)
        {
            struct timeval  begin, end;
            double          duration;
            gettimeofday(&begin, NULL);
            FillContainer(container, argc, argv);
            MergeInsertion(container.begin(), container.end());
            gettimeofday(&end, NULL);
            duration = ((end.tv_sec - begin.tv_sec) * 1000000ULL + end.tv_usec - begin.tv_usec) / 1000.0;
            std::cout << "Time to process a range of " << container.size() << " elements with " << type << " : " << duration << " ms" << std::endl;
        }

        virtual ~PmergeMe() = 0;

    private:
        static const int    K = 10;

        template<typename Container>
        static void FillContainer(Container& container, int argc, char** argv) {
            for (int i = 1; i < argc; ++i) {
                std::istringstream  iss(argv[i]);
                int n = 0;
                iss >> n;
                container.push_back(n);
            }
        }

        template<typename Iterator>
        static void MergeInsertion(Iterator begin, Iterator end) {
            typename std::iterator_traits<Iterator>::difference_type    size = std::distance(begin, end);

            Iterator    mid(begin);
            std::advance(mid, size / 2);

            if (size <= K) {
                Insertion(begin, end);
            } else {
                MergeInsertion(begin, mid);
                MergeInsertion(mid, end);
                std::inplace_merge(begin, mid, end);
            }
        }

        template<typename Iterator>
        static void Insertion(Iterator begin, Iterator end) {
            Iterator                        it(begin);
            std::reverse_iterator<Iterator> rend(begin);
            for (++it; it != end; ++it) {
                int tmp = *it;
                std::reverse_iterator<Iterator> j(it);
                for (;j != rend && *j > tmp; ++j)
                    std::swap(*std::prev(j), *j);
            }
        }

        template<typename T>
        static void DisplayValues(const T& value) {
            std::cout << " " << value;
        }

        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe&   operator=(const PmergeMe& rhs);
};

#endif  // PMERGE_ME_HPP_
