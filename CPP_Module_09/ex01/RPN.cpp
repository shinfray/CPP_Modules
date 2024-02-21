/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:26:10 by shinfray          #+#    #+#             */
/*   Updated: 2024/02/01 19:18:39by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cstdlib>
#include <iostream>

RPN::RPN(const std::string& equation) : equation_(equation)
{
}

RPN::RPN(const RPN& src)
{
    *this = src;
}

RPN&    RPN::operator=(const RPN& rhs)
{
    if (this != &rhs)
        this->equation_ = rhs.equation_;
    return *this;
}

RPN::~RPN()
{
}

void    RPN::PrintResult() const
{
    if (equation_.empty() == true)
        return;
    std::stack<const int> stack;
    const std::string::const_iterator   ite = equation_.end();
    for (std::string::const_iterator it = equation_.begin(); it != ite; ++it) {
        if (std::isdigit(*it) == true)
            stack.push(std::atoi(std::string(it, it + 1).c_str()));
        else
            DoOperation(stack, *it);
        if (it + 1 != ite) {
            ++it;
            if (*it != ' ' || it + 1 == ite)
                throw WrongFormatException();
        }
    }
    if (stack.size() > 1)
        throw TooManynumbersException();
    std::cout << stack.top() << std::endl;
}

void    RPN::DoOperation(std::stack<const int>& stack, const char op) const
{
    static const std::string    list("+-*/");
    if (list.find(op) == std::string::npos)
        throw UnknownOperationException();
    if (stack.size() < 2)
        throw NotEnoughNumbersException();
    const int b = stack.top();
    stack.pop();
    const int a = stack.top();
    stack.pop();
    switch (op) {
        case '+':
            stack.push(a + b);
            break;
        case '-':
            stack.push(a - b);
            break;
        case '*':
            stack.push(a * b);
            break;
        case '/':
            if (b == 0)
                throw DivideByZeroException();
            stack.push(a / b);
            break;
        default:
            throw UnknownOperationException();
            break;
    }
}
