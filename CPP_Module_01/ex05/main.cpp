/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:04:04 by shinfray          #+#    #+#             */
/*   Updated: 2023/12/11 21:38:03 by shinfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl    harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("NOT A LEVEL");
    harl.complain("ERROR");
    harl.complain("WARNING");
    harl.complain("INFO");
    harl.complain("DEBUG");
    harl.complain("NOT A LEVEL");
    return 0;
}
