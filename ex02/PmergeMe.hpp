/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:06:42 by kdoulyaz          #+#    #+#             */
/*   Updated: 2023/03/18 21:06:50 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

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
# endif

class PmergeMe
{
public:
		PmergeMe(int ac, char **av);
		~PmergeMe();
		template <typename T>
		void display(const T& container);
		void mergeInsertSortDeque(std::deque<int>& arr);
		void mergeInsertSortList(std::list<int>& arr);


private:
    PmergeMe();
    PmergeMe(PmergeMe const &);

    PmergeMe    &operator=(PmergeMe const &);
};
std::ostream	&operator<<( std::ostream &ostream, const PmergeMe &myClass );