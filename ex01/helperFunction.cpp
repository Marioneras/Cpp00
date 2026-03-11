/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperFunction.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:24:05 by mberthou          #+#    #+#             */
/*   Updated: 2026/02/05 19:24:29 by mberthou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>

#include "PhoneBook.hpp"
#include "colours.hpp"

bool isNumber(const std::string &str) {
	if (str.empty())
        return false;

    for (std::string::size_type i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    return true;
}

void	Contact::setField(Field index, bool (*validateField)(const std::string&),
		const std::string &prompt, const std::string &errorMessage) {
	std::cout << "Inscribe thy given "<< prompt << ": ";
	std::string	userInput;
	getline(std::cin, userInput);
	if (std::cin.eof() == 1) {
		std::cout << RED << "Ctrl+D entered" << RESET << std::endl;
		std::exit(EXIT_FAILURE);
	}
	while (userInput.size() == 0) {
		std::cout << RED << errorMessage << RESET << std::endl;
		std::cout << "> ";
		getline(std::cin, userInput);
	}
	if (validateField) {
		while (!validateField(userInput)) {
			std::cout << RED << errorMessage << RESET << std::endl;
			std::cout << "> ";
			getline(std::cin, userInput);
		}
	}
	field[index] = userInput;
}

const std::string	&Contact::getField(int index) {
	if (index > 4)
		throw std::out_of_range("Index out of range");
	return (field[index]);
}

void	Contact::printFixedWidthField(const std::string &text, std::size_t width) {
	int	isBigger = text.size() > width;

	std::string	sub = text.substr(0, width - isBigger);
	std::cout.fill(' ');
	std::cout.width(width - isBigger);
	std::cout << std::right << sub;
	std::cout << (char)(isBigger * '.');
}

void	Contact::displayContact(int i) {
	std::string contactField[5];

	std::string	index;
	std::stringstream str;
	i++;
	str << i;
	str >> index;

	for (int i = 0; i < 5; i++)
		contactField[i] = getField(i);

	std::cout << '|';
	printFixedWidthField(index);
	std::cout << '|';
	for (int i = 0; i < 3; i++) {
		printFixedWidthField(contactField[i]);
		std::cout << '|';
	}
	std::cout << std::endl;
}

void	Contact::displayContactInfos() {
	std::string	contactField[5];
	std::string	prompts[] = {
		"First name : ",
		"Last name : ",
		"Nickname : ",
		"Phone number : ",
		"Darkest secret : "
	};

	for (int i = 0; i < 5; i++)
		contactField[i] = getField(i);

	for (int i = 0; i < 5; i++)
		std::cout << prompts[i] << contactField[i] << std::endl;
}
