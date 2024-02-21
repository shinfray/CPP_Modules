/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:37:27 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/04 12:34:40 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP_
# define MUTANT_STACK_HPP_

#include <stack>

template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
        MutantStack<T, Container>() {}
        MutantStack<T, Container>(const MutantStack<T, Container>& src) {
            *this = src;
        }
        MutantStack<T, Container>& operator=(const MutantStack<T, Container>& rhs) {
            if (this != &rhs)
                std::stack<T, Container>::operator=(rhs);
            return *this;
        }

        ~MutantStack<T, Container>() {}

        typedef typename Container::iterator                iterator;
        typedef typename Container::const_iterator          const_iterator;
        typedef typename Container::reverse_iterator        reverse_iterator;
        typedef typename Container::const_reverse_iterator  const_reverse_iterator;

        iterator    begin() {
            return this->c.begin();
        }

        iterator  end() {
            return this->c.end();
        }

        const_iterator  begin() const {
            return this->c.begin();
        }

        const_iterator  end() const {
            return this->c.end();
        }

        reverse_iterator    rbegin() {
            return this->c.rbegin();
        }

        reverse_iterator    rend() {
            return this->c.rend();
        }

        const_reverse_iterator  rbegin() const {
            return this->c.rbegin();
        }

        const_reverse_iterator  rend() const {
            return this->c.rend();
        }
};

#endif  // MUTANT_STACK_HPP_
