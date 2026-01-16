/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:45:49 by mberthou          #+#    #+#             */
/*   Updated: 2025/12/03 14:45:49 by mberthou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

#include <iostream>
#include <string>

void	setField(std::string &field, bool (*validateField)(const std::string&),
		const std::string &prompt, const std::string &errorMessage) {
	std::cout << "Enter your "<< prompt << ": ";
	getline(std::cin, field);
	if (std::cin.gcount() == 0)
		throw std::exception(errorMessage);
	if (validateField)
		validateField(field);
}

void	PhoneBook::add() {
	int		indexEmptyContact = findEmptyField(ListOfContact);
	Contact	&contact = ListOfContact[indexEmptyContact];
	std::string	prompts[5] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
	};
	std::string errorMessage[5] = {
		"You must enter a name",
		"You must enter a name",
		"You must enter a nickname",
		"This is not a valid phone Number, please try again",
		"Don't try to mess with me... Everybody has a dark secret!",
		"File did not end with newline"
	};

	for (int i = 0; i < 5; i++)
		setField(contact.field[i], (i == 3) * isNumber, prompts[i],errorMessage[i]);
}

int	main() {
	string		user_input;
	PhoneBook	phonebook;

	std::cout << "Welcome to your AMAZING PhoneBook !" << endl;
	std::cout << "You can add a new contact by entering ADD,";
	std::cout << " search for a specific one by entering SEARCH";
	std::cout << " or simply exit the program by entering EXIT" << endl;

	while (42) {
		std::getline(std::cin, user_input);
		if (std::cin.eof() == 1) {
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		if (std::strncmp(user_input, "ADD", 4) == 0)
			phonebook.add();
		else if (std::strncmp(user_input, "SEARCH", 7) == 0)
			phonebook.search();
		else if (std::strncmp(user_input, "EXIT", 5) == 0)
			phonebook.exit();
		else {
			std::cout << "This command doesn't exist,";
			std::cout << " please, try typping ADD, SEARCH or EXIT" << endl;
		}
	}
	return (0);
}
