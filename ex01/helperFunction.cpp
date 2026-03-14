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

bool	stringToInt(const std::string &str, int &result)
{
    std::stringstream ss(str);
    ss >> result;

    if (ss.fail() || !ss.eof())
        return false;
    return true;
}

bool	isNumber(const std::string &str) {
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
	if (std::cin.eof()) {
		std::cout << std::endl;
		std::cerr << RED << "Ctrl+D entered" << RESET << std::endl;
		std::exit(EXIT_FAILURE);
	}
	while (userInput.size() == 0) {
		std::cerr << RED << errorMessage << RESET << std::endl;
		std::cout << "> ";
		getline(std::cin, userInput);
	}
	if (validateField) {
		while (!validateField(userInput)) {
			std::cerr << RED << errorMessage << RESET << std::endl;
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

	std::cout << std::endl;
}

void	PhoneBook::displayMenuPrompt() {
	std::cout	<< std::endl << BLUE
				<< "Very well — your request has been duly attended to."
				<< std::endl << std::endl
				<< "You now find yourself once more before the pages of this "
				<< "Amazing Phonebook." << std::endl
				<< "Should further business require my attention, "
				<< "you may inscribe a new entry with ADD, "
				<< "consult the register with SEARCH, "
				<< "or close the directory with EXIT." << std::endl
				<< std::endl
				<< "How shall we proceed?" << RESET << std::endl;
}

int	PhoneBook::displayTable() {
	std::cout	<< "/----------.----------.----------.----------\\" << std::endl
				<< "|  Index   |First name|Last  name| Nickname |" << std::endl
				<< "}----------+----------+----------+----------{" << std::endl;

	int i = 0;
	for (;i < ((addCount < 8) ? addCount : 8); i++) {
		listOfContact[i].displayContact(i);
	}

	std::cout	<< "\\----------'----------'----------'----------/" << std::endl
				<< std::endl;
	return (i);
}

std::string	PhoneBook::askIndex() {
	std::string	userInput;

	std::cout	<< BLUE << "Pray, select the contact whose particulars you "
				<< "desire to view, or come back to the menu with EXIT:"
				<< RESET << std::endl << "> ";
	std::getline(std::cin, userInput);
	if (std::cin.eof()) {
		std::cout << std::endl;
		std::cerr << RED << "Ctrl+D entered" << RESET << std::endl;
		std::exit(EXIT_FAILURE);
	}

	return (userInput);
}
