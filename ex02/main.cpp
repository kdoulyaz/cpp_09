/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:06:10 by kdoulyaz          #+#    #+#             */
/*   Updated: 2023/03/18 21:06:14 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac <= 1 || !av[1][0])
    {
        std::cerr << RED << "Error: No input sequence provided." << NONE << std::endl;
        return (1);
    }
	PmergeMe pmergeMe(ac, av);
	(void)pmergeMe;
    return (0);
}