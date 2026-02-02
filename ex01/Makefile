# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/21 18:51:02 by mberthou          #+#    #+#              #
#    Updated: 2025/11/21 19:07:06 by mberthou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++
CFLAGS = -Wall -Wextra -Werror
NAME = TheAmazingPhoneBook
SOURCES = PhoneBook.cpp helperFunction.cpp

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCES)

clean:
	rm -rf $(NAME)
