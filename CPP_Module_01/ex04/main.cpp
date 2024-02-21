/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:37:48 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/15 11:08:51 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string ConvertInputFileToString(std::ifstream& input_file);
void        UpdateBuff(std::string& buff, const std::string& to_replace,
                       const std::string& to_replace_with);

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cout << "Usage: ./Sed_is_for_losers \"inputfile\" \"string to replace\" \"string to replace with\"" << std::endl;
        return 1;
    }

    std::string     input_filename(argv[1]);
    std::ifstream   input_file(argv[1]);
    if (input_file.good() == false) {
        std::cout << "Error when opening: " << input_filename << std::endl;
        return 2;
    }
    std::string     output_filename(input_filename + ".replace");
    std::ofstream   output_file(output_filename, std::ios::out | std::ios::trunc);
    if (output_file.good() == false) {
        std::cout << "Error when creating: " << output_filename << std::endl;
        return 3;
    }

    std::string buff(ConvertInputFileToString(input_file));

    UpdateBuff(buff, argv[2], argv[3]);

    output_file << buff;
    if (output_file.good() != true) {
        std::cout << "Error when writing to " << output_filename << std::endl;
        return 4;
    }

    return 0;
}

std::string ConvertInputFileToString(std::ifstream& input_file)
{
    std::ostringstream string_stream(std::ios::out);

    string_stream << input_file.rdbuf();
    std::string buff(string_stream.str());
    string_stream.str(std::string());
    return buff;
}

void    UpdateBuff(std::string& buff, const std::string& to_replace,
                   const std::string& to_replace_with)
{
    size_t  head(0);
    while ((head = buff.find(to_replace, head)) != std::string::npos) {
        buff.insert(head, to_replace_with);
        head += to_replace_with.size();
        buff.erase(head, to_replace.size());
    }
}
