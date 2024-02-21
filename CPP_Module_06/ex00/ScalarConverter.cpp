/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 03:32:00 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/23 04:06:50y shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::~ScalarConverter()
{
}

void    ScalarConverter::convert(const std::string& str)
{
    if (str.size() == 0) {
        std::cout << "ERROR: No value to convert" << std::endl;
        return;
    }

    FuncGetType     detect_type_f[kTypeNumber] = {&ScalarConverter::isChar,
                                                  &ScalarConverter::isInt,
                                                  &ScalarConverter::isDouble,
                                                  &ScalarConverter::isFloat};
    FuncConvertType convert_type_f[kTypeNumber] = {&ScalarConverter::fromChar,
                                                   &ScalarConverter::fromInt,
                                                   &ScalarConverter::fromDouble,
                                                   &ScalarConverter::fromFloat};
    
    size_t  i = 0;
    for (; i < kTypeNumber && (*detect_type_f[i])(str) == false; ++i)
        ;
    if (i == kTypeNumber) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    (*convert_type_f[i])(str);
}

bool    ScalarConverter::isChar(const std::string& str)
{
    return (str.size() == 3 && std::isprint(str[1]) == true &&
            str.front() == '\'' && str.back() == '\'');
}

bool    ScalarConverter::isInt(const std::string& str)
{
    std::istringstream  iss(str);
    int  i;
    iss >> std::noskipws >> i;
    return iss.eof() && !iss.fail(); 
}

bool    ScalarConverter::isDouble(const std::string& str)
{
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;
    std::istringstream  iss(str);
    double  d;
    iss >> std::noskipws >> d;
    if (isnan(d) == true || isinf(d) == true)
        return false;
    return iss.eof() && !iss.fail(); 
}

bool    ScalarConverter::isFloat(const std::string& str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;
    try
    {
        if (std::isspace(str.front()))
            throw std::exception();
        size_t  i = 0;
        float   f = std::stof(str, &i);
        if (isnan(f) == true || isinf(f) == true)
            return false;
        if ((str.substr(i, std::string::npos)).size() != 1 || str.back() != 'f')
            throw std::exception();
        return true;
    }
    catch(const std::exception& e)
    {
        return false;
    }
}

void    ScalarConverter::fromChar(const std::string& str)
{
    char    c = str[1];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void    ScalarConverter::fromInt(const std::string& str)
{
    int     i = std::stoi(str);
    if (i > static_cast<int>(std::numeric_limits<char>::max()) ||
            i < static_cast<int>(std::numeric_limits<char>::min()))
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(i)) == false)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void    ScalarConverter::fromFloat(const std::string& str)
{
    if (str == "-inff" || str == "+inff" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
		return ;
	}
    float   f = std::stof(str);
    if (f > static_cast<float>(std::numeric_limits<char>::max()) ||
            f < static_cast<float>(std::numeric_limits<char>::min()))
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(f)) == false)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    if (f > static_cast<float>(std::numeric_limits<int>::max()) ||
            f < static_cast<float>(std::numeric_limits<int>::min()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f;
    if (std::round(f) == f)
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f);
    if (std::round(f) == f)
        std::cout << ".0";
    std::cout << std::endl;
}

void    ScalarConverter::fromDouble(const std::string& str)
{
    if (str == "-inf" || str == "+inf" || str == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return ;
	}
    double  d = std::stod(str);
    if (d > static_cast<double>(std::numeric_limits<char>::max()) ||
            d < static_cast<double>(std::numeric_limits<char>::min()))
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(d)) == false)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    if (d > static_cast<double>(std::numeric_limits<int>::max()) ||
            d < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    if (isinf(static_cast<float>(d)) == true)
        std::cout << "float: impossible" << std::endl;
    else {
        std::cout << "float: " << static_cast<float>(d);
        if (std::round(d) == d)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    std::cout << "double: " << d;
    if (std::round(d) == d)
        std::cout << ".0";
    std::cout << std::endl;
}
