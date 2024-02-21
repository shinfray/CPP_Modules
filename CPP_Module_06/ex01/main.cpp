/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:50:06 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/25 18:50:07 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data    data_1;
    Data    data_2(21, 'c', "bonjour tout le monde!");
    Data    data_3(data_2);

    std::cout << "========DATA_1========" << std::endl;
    std::cout << data_1 << std::endl;
    std::cout << "========DATA_2========" << std::endl;
    std::cout << data_2 << std::endl;
    std::cout << "========DATA_3========" << std::endl;
    std::cout << data_3 << std::endl;

    std::cout << "=======ADDRESSES=======" << std::endl;
    std::cout << "data_1: " << &data_1 << std::endl;
    std::cout << "data_2: " << &data_2 << std::endl;
    std::cout << "data_3: " << &data_3 << std::endl;

    std::cout << "=======SERIALIZE=======" << std::endl;
    uintptr_t   uintptr_1 = Serializer::serialize(&data_1);
    uintptr_t   uintptr_2 = Serializer::serialize(&data_2);
    uintptr_t   uintptr_3 = Serializer::serialize(&data_3);

    std::cout << "uintptr_1: " << uintptr_1 << std::endl;
    std::cout << "uintptr_2: " << uintptr_2 << std::endl;
    std::cout << "uintptr_3: " << uintptr_3 << std::endl;

    std::cout << "======DESERIALIZE======" << std::endl;
    Data*   data_ptr_1 = Serializer::deserialize(uintptr_1);
    Data*   data_ptr_2 = Serializer::deserialize(uintptr_2);
    Data*   data_ptr_3 = Serializer::deserialize(uintptr_3);

    std::cout << "data_ptr_1: " << data_ptr_1 << std::endl;
    std::cout << "data_ptr_2: " << data_ptr_2 << std::endl;
    std::cout << "data_ptr_3: " << data_ptr_3 << std::endl;

    std::cout << "========DATA_1========" << std::endl;
    std::cout << *data_ptr_1 << std::endl;
    std::cout << "========DATA_2========" << std::endl;
    std::cout << *data_ptr_2 << std::endl;
    std::cout << "========DATA_3========" << std::endl;
    std::cout << *data_ptr_3 << std::endl;

    return 0;
}
