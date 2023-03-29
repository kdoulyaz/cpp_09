/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:12:41 by kdoulyaz          #+#    #+#             */
/*   Updated: 2023/03/18 21:12:46 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <exception>
#include <sstream>
#include <cstdlib>

# ifndef COLOR
#  define COLOR

#  define RED		"\033[1;31m"
#  define WHITE		"\033[1;37m"
#  define GREEN		"\033[1;32m"
#  define CYANE		"\033[1;36m"
#  define YELLOW	"\033[1;33m"
#  define NONE		"\033[0;37m"
#  define DIVI		47
#  define MOIN		45
#  define PLUS		43
#  define MULT		42
# endif


class Rpn
{
    public:
        Rpn();
        ~Rpn();

        void                        calcPolish(char *argv);

    private:
        Rpn(Rpn const &);
        Rpn &operator=(Rpn const &);
        bool    testAlpha(char alpha) const;
        void    check_pol(char *pol);
        bool    testOperation(char alpha) const;

        std::stack<int>   _datas;
};
std::ostream	&operator<<( std::ostream &ostream, const Rpn &myClass );