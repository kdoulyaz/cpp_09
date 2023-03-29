/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <kdoulyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:14:24 by kdoulyaz          #+#    #+#             */
/*   Updated: 2023/03/28 18:42:08 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

void    print_err(std::string err, std::string tmp)
{
    std::cout << RED << err << tmp << NONE << std::endl;
    exit (1);
}

BitcoinExchange::BitcoinExchange(char *fichierTxt) : _fichierTxt(fichierTxt)
{
    std::string tmp;

    monFlux.open(FICHIER_CSV);
    if (!monFlux)
        print_err(errorOpen, FICHIER_CSV);
    getline(monFlux, buffer);
    if (!buffer[0])
        print_err(errorFormat, FICHIER_CSV);
    parsing = buffer.rfind("exchange");
    buffer.erase(parsing);
    parsingCsv = buffer.substr(4);
    while (getline(monFlux, buffer))
    {
        if (!check(buffer))
            continue;
        size_t  i = buffer.find("\r");
        if (i != std::string::npos)
            buffer.erase(i);
        i = buffer.find(parsingCsv.c_str());
        if (i == std::string::npos)
            print_err(errorFormat, FICHIER_CSV);
        val = atof(buffer.substr(i + 1).c_str());
        if (val < 0)
            print_err(errorNegativeNumber, "");
        if (i)
            buffer.erase(i);
        else
            print_err(errorBadInput, "");
        _datas.insert(std::pair<std::string, float>(buffer, val));
        tmp = buffer;
        
    }
    if (!tmp[0])
        print_err("Error: empty file ", "data.csv");
    monFlux.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

std::map<int, std::string> splitString(const std::string& str, const std::string& delimiter) {
    std::map<int, std::string> substrings;
    std::string::size_type pos = 0;
    int index = 0;
    std::string s = str;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        substrings[index++] = s.substr(0, pos);
        s.erase(0, pos + delimiter.length());
    }
    substrings[index] = s;
    return substrings;
}

bool    check(std::string buff)
{
    std::string delimiter = " ";
    int         j = 0;

    if (!buff[0])
    {
        std::cout << RED error_line << FICHIER_CSV NONE << std::endl;
        return (false);
    }
    std::map<int, std::string> sub_str = splitString(buff, delimiter);

     for (std::map<int, std::string>::iterator it = sub_str.begin(); it != sub_str.end(); ++it) {
        j++;
        std::string sub_str = it->second;
        for (size_t i = 0; i < sub_str.length(); ++i) {
            if (!(isdigit(it->second[i]) || it->second[i] == '-' || it->second[i] == '|' || it->second[i] == '.' || it->second[i] == ',')) {
                std::cout << RED << errorBadInput << buff << NONE << std::endl;
                return (false);
        }
        }
     }
    if (j > 3)
    {
        std::cout << RED << errorBadInput << buff << NONE << std::endl;
        return (false); 
    }
    return (true);
}

void    BitcoinExchange::calcValueBitcoin(){

    std::string     buffer;
    
    monFlux.open(_fichierTxt.c_str());
    if (!monFlux)
    {
        std::cout << RED errorOpen << "\"" << _fichierTxt << "\"" << NONE << std::endl;
        exit(1);
    }
    getline(monFlux, buffer);
    while (getline(monFlux, buffer))
    {
        if (buffer == "")
        {
            std::cout << RED error_line  NONE << std::endl;
            continue;
        }
        size_t  i = buffer.find("\r"); 
        if (i != std::string::npos)
            buffer.erase(i);
        if (!check(buffer))
            continue;
        i = buffer.find("| ");
        if (i == std::string::npos)
        {
            if (!testDateValide(buffer))
                std::cout << RED errorBadInput << buffer << NONE << std::endl;
            else
                std::cout << RED  errorFormat NONE << std::endl;
            continue;
        }
        nbBitcoin = atof(buffer.substr(i + 2).c_str());
        if (nbBitcoin > FLOAT_MAX)
        {
            std::cout << RED  errorTooLargeNumber NONE << std::endl;
            continue;
        }
        if (nbBitcoin < 0)
        {
            std::cout << RED <<  errorNegativeNumber << NONE << std::endl;
            continue;
        }
        if (i)
            buffer.erase(i - 1);
        else
        {
            std::cout << RED errorFormat NONE << std::endl;
            continue;
        }
        if (testDate(buffer))
            val = _datas[buffer];
        else
        {
            if (testDateValide(buffer))
            {
                temp = searchValueBefore(buffer);
                if (temp != "")
                    val = _datas[temp];
                else
                {
                    std::cout << RED  noValueBefore << buffer << NONE << std::endl;
                    continue;
                }
            }
            else
            {
                std::cout << RED errorBadInput << buffer << NONE << std::endl;
                continue;
            }
            
        }
        std::cout << buffer << " => " << nbBitcoin <<  " = " << val * nbBitcoin << std::endl;
    }
    monFlux.close();
}

bool    BitcoinExchange::testDate(std::string const &date){
    bool    status = false;
    for (std::map<std::string, float>::iterator it = _datas.begin(); it != _datas.end(); it++)
    {
        if (date == it->first)
        {
            status = true;
            break;
        }   
    }
    return status;
}

bool    BitcoinExchange::testDateValide(std::string const &date){
    std::string     temp = date;
    std::string     temp2;
    size_t          i;
    int             val;

    // ******  Day  ******
    i = temp.rfind('-');
    temp2 = temp.substr(i + 1);
    temp.erase(i);
    val = atoi(temp2.c_str());
    if (val < 1 || val > 31)
        return false;
        
    // ******  Month  ******
    i = temp.rfind('-');
    temp2 = temp.substr(i + 1);
    temp.erase(i);
    val = atoi(temp2.c_str());
    if (val < 1 || val > 12)
        return false;

    // ******  Year  ******
    val = atoi(temp.c_str());
    if (val < 2000 || val > 2100)
        return false;   

    return true;
}

std::string BitcoinExchange::searchValueBefore(std::string const &date)
{
    std::map<std::string, float>::iterator itBefore = _datas.end();

    for (std::map<std::string, float>::iterator it = _datas.begin(); it != _datas.end(); it++)
    {
        if (date > it->first)
            itBefore = it;
        else
        {
            if (itBefore != _datas.end())
                return (itBefore->first);
            return "";
        }
    }
    return (itBefore->first);
}
