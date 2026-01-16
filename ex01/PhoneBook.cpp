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

void	PhoneBook::add() {
	int		indexEmptyContact = findEmptyField(listOfContact);
	Contact	&contact = listOfContact[indexEmptyContact];
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
		setField(contact.field[i], (i == 3) * isNumber, prompts[i], errorMessage[i]);
	contact.isSet = true;
}

void	PhoneBook::search() {
	string	userInput;

	for (int i = 0, listOfContact[i].isSet; i++)
		displayContact(listOfContact[i]);
	std::cout << "Select the contact you want the infos to be displayed:" << endl;
	std::getline(std::cin, userInput);
	if (std::cin.eof() == 1) {
		std::cin.clear();
		std::cin.ignore();
		continue;
	}

}

int	main() {
	string		userInput;
	PhoneBook	phonebook;

	std::cout << "Welcome to your AMAZING PhoneBook !" << endl;
	std::cout << "You can add a new contact by entering ADD,";
	std::cout << " search for a specific one by entering SEARCH";
	std::cout << " or simply exit the program by entering EXIT" << endl;

	while (42) {
		std::getline(std::cin, userInput);
		if (std::cin.eof() == 1) {
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		if (std::strncmp(userInput, "ADD", 4) == 0)
			phonebook.add();
		else if (std::strncmp(userInput, "SEARCH", 7) == 0)
			phonebook.search();
		else if (std::strncmp(userInput, "EXIT", 5) == 0)
			phonebook.exit();
		else {
			std::cout << "This command doesn't exist,";
			std::cout << " please, try typping ADD, SEARCH or EXIT" << endl;
		}
	}
	return (0);
}
