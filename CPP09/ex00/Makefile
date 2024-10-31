# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 19:00:06 by angassin          #+#    #+#              #
#    Updated: 2024/10/31 18:19:29 by angassin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#-------------------------------COLORS------------------------------------------

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
BLUE='\033[1;94m'
RED='\033[1;91m'

#-------------------------------VARIABLES---------------------------------------

NAME = btc

CXX	= c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -MMD -MP

SRC_DIR = srcs

SRCS = srcs/main.cpp srcs/BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

DEBUG		= 0

SANI		= 0

ifeq ($(SANI), 1)
	CPPFLAGS += 	-fsanitize=address -fsanitize=undefined \
				-fno-sanitize-recover=all	-fsanitize=float-divide-by-zero \
				-fsanitize=float-cast-overflow -fno-sanitize=null \
				-fno-sanitize=alignment
	DEBUG = 1
endif

ifeq ($(DEBUG), 1)
	CPPFLAGS += -g3
endif

#---------------------------------RULES-----------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)
	
$(SRC_DIR)/%o: $(SRC_DIR)/%.cpp
	@echo $(GRAY)"Compiling...";
	@$(CXX) $(CPPFLAGS)  -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(DEPS)
	@rm -f $(NAME)


re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
