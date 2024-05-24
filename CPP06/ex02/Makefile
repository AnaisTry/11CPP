# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angassin <angassin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 12:17:22 by angassin          #+#    #+#              #
#    Updated: 2024/05/24 15:17:03 by angassin         ###   ########.fr        #
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

NAME = identify

CXX	= c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

SRC_DIR = srcs

SRCS = srcs/main.cpp srcs/Base.cpp

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
	@$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)
	
$(SRC_DIR)/%o: $(SRC_DIR)/%.cpp
	@echo $(GRAY)"Compiling...";
	@$(CXX) $(CPPFLAGS)  -c $< -o $@


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
