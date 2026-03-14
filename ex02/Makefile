# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/14 23:33:10 by mberthou          #+#    #+#              #
#    Updated: 2026/03/14 23:49:21 by mberthou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = Account.cpp tests.cpp
NAME = gitRestore
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
OBJECTS = $(SOURCES:.cpp=.o)

all: $(OBJECTS)
	c++ -o $(NAME) $(OBJECTS)

%.o: %.cpp
	c++ -o $@ -c $< $(CPP_FLAGS)

clean :
	rm $(OBJECTS)

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY: all clean fclean re
