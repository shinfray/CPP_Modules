/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:50:25 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/25 19:51:58 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

int main()
{
    std::cout << "======with poiter======" << std::endl;
    for(int i = 0; i < 5; ++i) {
        Base* base = generate();
        identify(base);
        delete base;
    }
    std::cout << "======with reference======" << std::endl;
    for(int i = 0; i < 5; ++i) {
        Base* base = generate();
        identify(*base);
        delete base;
    }
    return 0;
}

Base*   generate()
{
    static bool seeded;

    if (seeded == false) {
        std::srand(time(NULL));
        seeded = true;
    }
    switch (std::rand() % 3) {
        case 0:
            std::cout << "generate A" << std::endl;
            return new A;
            break;
        case 1:
            std::cout << "generate B" << std::endl;
            return new B;
            break;
        default:
            std::cout << "generate C" << std::endl;
            return new C;
            break;
    }
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "This is a pointer to A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "This is a pointer to B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "This is a pointer to C" << std::endl;
    else
        std::cout << "This is an unknown pointer type" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "This is a pointer to A" << std::endl;
        return;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "This is a pointer to B" << std::endl;
        return;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "This is a pointer to C" << std::endl;
        return;
    }
    catch(const std::exception& e) {}
}
