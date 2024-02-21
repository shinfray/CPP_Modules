/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:18:46 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/20 18:38:27 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    int grades_declaration[] = {10, 102, 1, 150, 0, 154};
    size_t  grades_declaration_size = sizeof(grades_declaration) / sizeof(*grades_declaration);
    for (size_t i = 0; i < grades_declaration_size; ++i) {
        try
        {
            std::cout << "========== [ TEST " << i + 1 << " ] ==========" << std::endl;
            std::cout << "Trying to create a new bureaucrat with level: " << grades_declaration[i] << std::endl;
            Bureaucrat  new_bureaucrat("Billy", grades_declaration[i]);
            std::cout << new_bureaucrat << std::endl;
            std::cout << std::endl;
            int forms[][2] = {{20, 2}, {102, 46}, {1, 5}, {150, 78}, {1, 150}, {150, 1}, {0, 34}, {76, 151}, {-4, 46}};
            size_t  forms_size = sizeof(forms) / sizeof(*forms);
            for (size_t j = 0; j < forms_size; ++j) {
                try
                {
                    std::cout << "+++++ [ FORM " << j + 1 << " ] +++++" << std::endl;
                    std::cout << "Trying to create a new form with sign and execute level: ";
                    std::cout << forms[j][0] << " / " << forms[j][1] << std::endl;
                    Form    new_form("random request", forms[j][0], forms[j][1]);
                    std::cout << new_form << std::endl;
                    new_bureaucrat.signForm(new_form);
                    std::cout << new_form << std::endl;
                    std::cout << std::endl;
                }
                catch (const std::exception& e)
                {
                    std::cout << "ERROR: " << e.what() << std::endl;
                    std::cout << std::endl;
                }
            }
        }
        catch (const std::exception& e)
        {
            std::cout << "ERROR: " << e.what() << std::endl;
            std::cout << std::endl;
        }
    }

    return 0;
}
