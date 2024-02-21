/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:10:10 by shinfray          #+#    #+#             */
/*   Updated: 2024/01/30 16:37:57y shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP_
# define BITCOIN_EXCHANGE_HPP_

# include <ctime>
# include <map>
# include <string>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange&    operator=(const BitcoinExchange& rhs);

        ~BitcoinExchange();

        static time_t   ParseDateTime(const char* date, const char* format);

        void    DisplayBtcPrice();
        void    AddPrice(const time_t date, const double price);
        void    ReadInputFile(const std::string& input_file);


        class FormatExchangeRateFileException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "format error in exchange_rate file";
                }
        };
        class DuplicateExchangeRateFileException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "exchange_rate file duplicates exception";
                }
        };
        class FormatInputFileException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "format error in input file";
                }
        };
        class DateFormatException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "bad input";
                }
        };
        class NotPositiveNumberException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "not a positive number";
                }
        };
        class TooHighNumberException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "too large a number";
                }
        };
        class TooOlddateException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return "this date precedes the oldest known reference value";
                }
        };
        
    private:
        void    PrintConversion(const std::string& str, std::string& key_buffer, std::string& value_buffer) const;

        std::map<const time_t, const double>    btc_price_;
};

#endif  // BITCOIN_EXCHANGE_HPP_
