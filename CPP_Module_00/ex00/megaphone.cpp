/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:01:41 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/11 19:42:41 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include <string>

static void         PrintDefaultMessage();
static void         PrintAllArgs(int argc, char** argv);
static std::string  ToUpperCase(const std::string& input);

int main(int argc, char** argv)
{
    if (argc == 1)
        PrintDefaultMessage();
    else
        PrintAllArgs(argc, argv);
    return 0;
}

static void PrintDefaultMessage()
{
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

static void PrintAllArgs(int argc, char** argv)
{
    for (int i(1); i < argc; ++i)
        std::cout << ToUpperCase(argv[i]);
    std::cout << std::endl;
}

static std::string  ToUpperCase(const std::string& input)
{
    std::locale     loc;
    std::string     result(input);
    const size_t    result_size(result.size());
    for (size_t i(0); i < result_size; ++i)
        result.replace(i, 1, 1, std::toupper(result[i], loc));
    return result;
}
