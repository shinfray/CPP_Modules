/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:37:42 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/07 16:48:53by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    std::string     string("HI THIS IS BRAIN");
    std::string*    stringPTR(&string);
    std::string&    stringREF(string);

    std::cout << "Memory address of string: " << &string << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << "Value of string: " << string << std::endl;
    std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF: " << stringREF << std::endl;
    return 0;
}