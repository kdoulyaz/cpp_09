/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:14:47 by kdoulyaz          #+#    #+#             */
/*   Updated: 2023/03/28 17:13:21 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
#include <cstdlib>
#include <iomanip> 

# ifndef COLOR
#  define COLOR
#  define CLEAR		"\x1B[2J\x1B[H"
#  define NONE		"\033[0;37m"
#  define WHITE		"\033[1;37m"
#  define RED		"\033[1;31m"
#  define GREEN		"\033[1;32m"
#  define CYANE		"\033[1;36m"
#  define ORANGE	"\033[1,38m"
#  define YELLOW	"\033[1;33m"
#  define BLUE		"\033[1,34m"
#  define GREY		"\033[1,37m"
#  define ROSE		"\033[35m"
#  define UNDER		"\033[4m"
#  define END		"\033[0m"

#  define errorOpen "Error: could not open file "
#  define errorFormat "Error: error format in the file "
#  define errorBadInput "Error: bad input => "
#  define errorTooLargeNumber "Error: too large a number."
#  define errorNegativeNumber "Error: not a positive number."
#  define error_line "Error: empty line in file"
#  define noValueBefore "Error: No date before "
# endif

#define FICHIER_CSV "data.csv"
#define FLOAT_MAX   1000

class BitcoinExchange
{
public:
    BitcoinExchange(char *fichierTxt);
    virtual ~BitcoinExchange();

    void    calcValueBitcoin();

private:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &);

    BitcoinExchange operator=(BitcoinExchange const &);

    bool        testDate(std::string const &date);
    bool        testDateValide(std::string const &date);
    std::string searchValueBefore(std::string const &date);

    std::map<std::string, float>    _datas;
    std::string                     _fichierTxt;
    std::ifstream   monFlux;
    std::string     buffer;
    std::string     temp;
    std::string     parsingCsv;
    float           val;
    size_t          parsing;
    float           nbBitcoin;
};

std::map<int, std::string> splitString(const std::string& str, const std::string& delimiter);
bool    check(std::string buff);