# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdoulyaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 21:14:31 by kdoulyaz          #+#    #+#              #
#    Updated: 2023/03/18 21:14:35 by kdoulyaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------Makefile--------------#

NAME := btc

SRC := main.cpp BitcoinExchange.cpp

CPP := c++ -Werror -Wextra -Wall -g -std=c++98

RED		=	\033[1;31m
YELLOW	=	\033[1;33m
RESET	=	\033[0m
CLEAR	=	\x1B[2J\x1B[H
NONE	=	\033[0;37m
WHITE	=	\033[1;37m
RED		=	\033[1;31m
GREEN	=	\033[1;32m
CYANE	=	\033[1;36m
ORANGE	=	\033[1,38m
YELLOW	=	\033[1;33m
BLUE	=	\033[1,34m
GREY	=	\033[1,37m
ROSE	=	\033[1,35m

all : $(NAME)
	@echo "$(CYANE)----------done------------$(RESET)"

$(NAME) : $(SRC)
	@$(CPP) $(SRC) -o $(NAME)

clean :
	@echo "$(GREEN)Cleaning up...$(RESET)"

fclean :
	@rm -f $(NAME)
	@echo "$(GREEN)Cleaned$(RESET)"

re : fclean all

.PHONY:		all clean fclean re