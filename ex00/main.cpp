/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:14:13 by kdoulyaz          #+#    #+#             */
/*   Updated: 2023/03/18 21:14:15 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        if (argc == 1)
            std::cerr << RED "Error: could not open file." NONE << std::endl;
        else
            std::cerr << RED "Error, too many arguments." NONE << std::endl;
        return (1);
    }
    
    try
    {
        BitcoinExchange bitCoin(argv[1]);
        bitCoin.calcValueBitcoin();
    }
    catch(const std::string &e)
    {
        std::cerr << RED <<  e << NONE << std::endl;
    }

    return (0);
}
