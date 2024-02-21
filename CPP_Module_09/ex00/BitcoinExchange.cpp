/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:11:13 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/30 15:43:12y shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
    std::ifstream   exchange_rate_file("data.csv");
    
    if (exchange_rate_file.good() == false)
        throw FormatExchangeRateFileException();
    std::string str("");
    std::getline(exchange_rate_file, str);
    if (str != "date,exchange_rate")
        throw FormatExchangeRateFileException();
    while (exchange_rate_file.eof() == false)
    {
        std::getline(exchange_rate_file, str);
        if (str.empty() == true)
            continue;
        try
        {
            const std::string::size_type    comma_pos = str.find(",");
            time_t  key = ParseDateTime(str.substr(0, comma_pos).c_str(), "%F");
            if (comma_pos == std::string::npos)
                throw FormatExchangeRateFileException();
            std::istringstream  iss(str.substr(comma_pos + 1));
            std::string         s(iss.str());
            double  value = 0;
            iss >> std::noskipws >> value;
            if (iss.fail() || !iss.eof() || (s[0] == '-' || s[0] == '+'))
                throw FormatExchangeRateFileException();
            AddPrice(key, value);
        }
        catch(const DuplicateExchangeRateFileException& e)
        {
            throw;
        }
        catch(const std::exception& e)
        {
            throw FormatExchangeRateFileException();
        }
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    *this = src;
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if (this != &rhs)
        this->btc_price_ = rhs.btc_price_;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

time_t  BitcoinExchange::ParseDateTime(const char* date, const char* format)
{
    struct tm   tm_struct = {};
    const char* ret = strptime(date, format, &tm_struct);
    if (ret == NULL || *ret != '\0')
        throw DateFormatException();
    time_t  result = mktime(&tm_struct);
    if (result == -1)
        throw DateFormatException();
    return mktime(&tm_struct);
}

void    BitcoinExchange::DisplayBtcPrice()
{
    std::cout << "[ date | exchange rate ]" << std::endl;
    const std::map<const time_t, const double>::const_iterator    ite = btc_price_.end();
    for(std::map<const time_t, const double>::const_iterator it = btc_price_.begin(); it != ite; ++it) {
        char    result_format[11] = "";
        std::strftime(result_format, 11, "%F", std::localtime(&it->first));
        std::cout << result_format << " | " << it->second << std::endl;
    }
}

void    BitcoinExchange::AddPrice(const time_t date, const double price)
{
    if (btc_price_.insert(std::pair<time_t, double>(date, price)).second == false)
        throw DuplicateExchangeRateFileException();
}

void    BitcoinExchange::ReadInputFile(const std::string& input_file)
{
    std::ifstream   file(input_file);
    if (file.good() == false)
        throw FormatInputFileException();
    std::string str("");
    std::getline(file, str);
    if (str != "date | value")
        throw FormatInputFileException();
    while (file.eof() == false) {
        std::getline(file, str);
        if (str.empty() == true)
            continue;
        std::string key_str("");
        std::string value_str("");
        try
        {
            PrintConversion(str, key_str, value_str);
        }
        catch(const DateFormatException& e)
        {
            std::cout << "Error: " << e.what() << " ==> " << key_str << std::endl;
        }
        catch(const NotPositiveNumberException& e)
        {
            std::cout << "Error: " << e.what() << "." << std::endl;
        }
        catch(const TooHighNumberException& e)
        {
            std::cout << "Error: " << e.what() << "." << std::endl;
        }
        catch(const TooOlddateException& e)
        {
            std::cout << "Error: " << e.what() << " ==> " << key_str << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "Error: bad format (date | value)" << std::endl;
        }
    }
}

void    BitcoinExchange::PrintConversion(const std::string& str, std::string& key_buffer, std::string& value_buffer) const
{
    const std::string::size_type    comma_pos = str.find(" | ");
    key_buffer = str.substr(0, comma_pos);
    time_t  key = ParseDateTime(key_buffer.c_str(), "%F");
    if (comma_pos == std::string::npos)
        throw FormatInputFileException();
    value_buffer = str.substr(comma_pos + 3);
    std::istringstream  iss(value_buffer);
    double  value = 0;
    iss >> std::noskipws >> value;
    if (iss.fail() || !iss.eof())
        throw FormatExchangeRateFileException();
    if (value < 0)
        throw NotPositiveNumberException();
    if (value > 1000)
        throw TooHighNumberException();
    if ((value_buffer[0] == '0' && value != 0) || (!std::isdigit(value_buffer[0])))
        throw FormatExchangeRateFileException();
    std::map<const time_t, const double>::const_iterator    it = btc_price_.upper_bound(key);
    if (it == btc_price_.begin())
        throw TooOlddateException();
    std::cout << key_buffer << " ==> " << value << " = " << (--it)->second * value << std::endl;
}
