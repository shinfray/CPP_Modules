/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:29:04 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/23 03:03:21by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP_
# define SCALAR_CONVERTER_HPP_

# include <string>

class ScalarConverter {
    public:
        virtual ~ScalarConverter() = 0;

        static void convert(const std::string& str);

    private:
        typedef bool (*FuncGetType)(const std::string&);
        typedef void (*FuncConvertType)(const std::string&);
        enum Types {
            kChar,
            kInt,
            kDouble,
            dFloat,
            kTypeNumber
        };

        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter&    operator=(const ScalarConverter& rhs);

        static bool isChar(const std::string& str);
        static bool isInt(const std::string& str);
        static bool isDouble(const std::string& str);
        static bool isFloat(const std::string& str);
        static void fromChar(const std::string& str);
        static void fromInt(const std::string& str);
        static void fromFloat(const std::string& str);
        static void fromDouble(const std::string& str);
};

#endif  // SCALAR_CONVERTER_HPP_
