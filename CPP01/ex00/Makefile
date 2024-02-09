# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 13:56:13 by angassin          #+#    #+#              #
#    Updated: 2024/02/09 20:38:39 by angassin         ###   ########.fr        #
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

NAME = zombie

CC	= c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Zombie.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

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
	@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)
	
%.o: %.cpp
	@echo $(GRAY)"Compiling...";
	@$(CC) $(CPPFLAGS)  -c $< -o $@


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re