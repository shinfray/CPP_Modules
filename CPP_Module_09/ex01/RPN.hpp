/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:25:31 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/04 13:06:23 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP_
# define RPN_HPP_

# include <exception>
# include <stack>
# include <string>

class RPN {
    public:
        RPN(const std::string& equation);
        RPN(const RPN& src);
        RPN&    operator=(const RPN& rhs);

        ~RPN();

        void    PrintResult() const;

        class WrongFormatException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "wrong equation format";
                }
        };
        class UnknownOperationException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "unknow operation";
                }
        };
        class NotEnoughNumbersException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "not enough numbers on the stack";
                }
        };
        class TooManynumbersException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "too many numbers on the stack";
                }
        };
        class DivideByZeroException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "divide by zero";
                }
        };
        
    private:
        RPN();

        void    DoOperation(std::stack<const int>& stack, const char op) const;

        std::string     equation_;
};

#endif  // RPN_HPP_
