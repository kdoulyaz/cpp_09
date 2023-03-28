/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoulyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:11:50 by kdoulyaz          #+#    #+#             */
/*   Updated: 2023/03/18 21:11:53 by kdoulyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Rpn.hpp"

int main(int argc, char **argv)
{
    if (argc != 2 || !argv[1][0])
    {
        std::cerr << RED "Error: Invalid input" NONE << std::endl;
        return (1);
    }

    Rpn polish;

    try
    {
        polish.calcPolish(argv[1]);
    }
    catch(std::string e)
    {
        std::cerr << RED << e << NONE << std::endl;
    }

    return (0);
}
