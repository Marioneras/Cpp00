/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperFunction.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:24:05 by mberthou          #+#    #+#             */
/*   Updated: 2025/12/03 18:24:05 by mberthou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

#include "PhoneBook.hpp"

bool isNumber(const std::string& str) {
	if (str.empty())
        return false;

    for (std::string::size_type i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    return true;
}

int	PhoneBook::findEmptyField()
{
	static int i = -1;

	if (i < 7)
		i++;
	else
		i = -1;
	return (i);
}

void	Contact::setField(Field index, bool (*validateField)(const std::string&),
		const std::string &prompt, const std::string &errorMessage) {
	std::cout << "Inscribe thy given "<< prompt << ": ";
	std::string	userInput;
	getline(std::cin, userInput);
	if (std::cin.eof() == 1) {
		std::cin.clear();
		std::cin.ignore();
		/* continue; */
	}
	if (userInput.size() == 0) {
		std::cout << errorMessage << std::endl;
		return ;
	}
	if (validateField) {
		if (validateField(userInput))
			field[index] = userInput;
		else {
			std::cout << errorMessage << std::endl;
			return ;
		}
	}
	else
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
	std::cout << std::left << sub;
	std::cout << (char)(isBigger * '.');
}

void	Contact::displayContact(int i) {
	std::string contactField[5];

	std::string	index;
	std::stringstream str;
	str << i;
	str >> index;

	for (int i = 0; i < 5; i++)
		contactField[i] = getField(i);

	std::cout << '|';
	printFixedWidthField(index + 1);
	std::cout << '|';
	for (int i = 0; i < 3; i++) {
		printFixedWidthField(contactField[i]);
		std::cout << '|';
	}
	std::cout << std::endl;
}

// void	Contact::displayContactInfos(contact &listOfContact) {
//
// }
