/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:18:46 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 18:38:11 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
    int grades_declaration[] = {10, 102, 1, 150, 0, 151, -4, 172};
    size_t  grades_declaration_size = sizeof(grades_declaration) / sizeof(*grades_declaration);
    for (size_t i = 0; i < grades_declaration_size; ++i) {
        try
        {
            std::cout << "========== [ SIMPLE TEST " << i + 1<< " ] ==========" << std::endl;
            std::cout << "Trying to create a new bureaucrat with level: " << grades_declaration[i] << std::endl;
            Bureaucrat  new_bureaucrat("Billy", grades_declaration[i]);
            std::cout << new_bureaucrat << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "ERROR: " << e.what() << std::endl;
            std::cout << std::endl;
        }
    }

    int grades_promotion[] = {10, 102, 2, 1};
    size_t  grades_promotion_size = sizeof(grades_promotion) / sizeof(*grades_promotion);
    for (size_t i = 0; i < grades_promotion_size; ++i) {
        try
        {
            std::cout << "========== [ PROMOTE TEST " << i + 1 << " ] ==========" << std::endl;
            Bureaucrat  new_bureaucrat("Billy", grades_promotion[i]);
            std::cout << new_bureaucrat << std::endl;
            std::cout << "Trying to promote new bureaucrat to level: " << grades_promotion[i] - 1<< std::endl;
            new_bureaucrat.promote();
            std::cout << new_bureaucrat << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "ERROR: " << e.what() << std::endl;
            std::cout << std::endl;
        }
    }

    int grades_demotion[] = {10, 102, 149, 150};
    size_t  grades_demotion_size = sizeof(grades_demotion) / sizeof(*grades_demotion);
    for (size_t i = 0; i < grades_demotion_size; ++i) {
        try
        {
            std::cout << "========== [ DEMOTE TEST " << i + 1 << " ] ==========" << std::endl;
            Bureaucrat  new_bureaucrat("Billy", grades_demotion[i]);
            std::cout << new_bureaucrat << std::endl;
            std::cout << "Trying to demote new bureaucrat to level: " << grades_demotion[i] + 1 << std::endl;
            new_bureaucrat.demote();
            std::cout << new_bureaucrat << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "ERROR: " << e.what() << std::endl;
            std::cout << std::endl;
        }
    }

    return 0;
}
