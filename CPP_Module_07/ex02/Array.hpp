/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:27:57 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/03 16:55:53 shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP_
# define ARRAY_HPP_

# include <exception>

template<typename T>
class Array {
    public:
        Array<T>() : size_(0), array_(new T[0]()) {}
        Array<T>(const Array& src) : array_(NULL) {
            *this = src;
        }
        Array&  operator=(const Array& rhs) {
            if (this == &rhs)
                return *this;
            delete [] this->array_;
            this->array_ = new T[rhs.size_];
            this->size_ = rhs.size_;
            for (size_t i = 0; i < rhs.size_; ++i)
                this->array_[i] = rhs.array_[i];
            return *this;
        }
        Array<T>(unsigned int size) : size_(size), array_(new T[size]()) {}

        ~Array<T>() {
            delete [] array_;
        }

        T&  operator[](unsigned int index) {
            if (index >= size_)
                throw OutOfRangeException();
            return array_[index];
        }

        unsigned int    size() const {
            return size_;
        }

        class OutOfRangeException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Out of range exception";
                }
        };
        
    private:
        unsigned int    size_;
        T*              array_;
};

#endif  // ARRAY_HPP_
