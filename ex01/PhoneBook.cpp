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

#include "PhoneBook.hpp"

#include <iostream>
#include <cstring>

void	PhoneBook::add() {
	int		indexEmptyContact = findEmptyField(listOfContact);
	Contact	&contact = listOfContact[indexEmptyContact];
	std::string	prompts[5] = {
		"first name",
		"last name",
		"nickname",
		"phone number (digits only, if you please—machines are literal creatures)",
		"darkest secret (stored discreetly, though never truly forgotten)"
	};
	std::string errorMessage[5] = {
		"Kindly furnish a name, if you please.",
		"Name must be furnished, I say!",
		"You must provide a moniker, pray tell",
		"That ain't no proper telephone number, give it another go, won't ya?",
		"Don't you triffle with me... Everybody has a skeleton in their closet!",
		"The file hath concluded without a newline, I say!"
	};

	for (int i = 0; i < 5; i++)
		setField(contact.field[i], (i == 3) * isNumber, prompts[i], errorMessage[i]);
	contact.isSet = true;
}

void	PhoneBook::search() {
	std::string	userInput;

	std::cout << "---------------------------------------------";
	std::cout << "|  Index   |First name|Last  name| Nickname |";

	for (int i = 0, listOfContact[i].isSet; i++)
		displayContact(listOfContact[i]);

	std::cout << "---------------------------------------------";

	std::cout << "Pray, select the contact whose particulars you desire to view:" << std::endl;
	std::getline(std::cin, userInput);
	if (std::cin.eof() == 1) {
		std::cin.clear();
		std::cin.ignore();
		continue;
	}
	int res = std::stoi(userInput);
	if (res > i || res < 0)
		throw std::execption("The digits ye provided be either beyond the pale or plumb incorrect.");
	displayContactInfos(listOfContact[res]);
}

int	PhoneBook::exit() {
	std::cout << "exit!" << std::endl;
	return (0);
}

int	main() {
	std::string	userInput;
	PhoneBook	phonebook;

	std::cout << "Good day to you, inquisitive caller." << std::endl;
	std::cout << "You have opened the Amazing Phonebook,";
	std::cout << "Edition Perpetual—once a humble book of paper and ink,";
	std::cout << "now enlivened by currents unseen." << endl;
	std::cout << "I stand ready to serve, faithfully and without gossip." << std::endl;
	std::cout << "Should you wish to inscribe a new name upon my ever-growing pages, enter ADD." << std::endl;
	std::cout << "If you seek a particular party already recorded, enter SEARCH." << std::endl;
	std::cout << "And should your business here be concluded, you may close my covers by entering EXIT." << std::endl;
	std::cout << "Pray tell, how may I be of assistance?" << std::endl;

	while (42) {
		std::getline(std::cin, userInput);
		if (std::cin.eof() == 1) {
			std::cin.clear();
			std::cin.ignore();
			/* continue; */
		}
		if (userInput.compare("ADD") == 0)
			phonebook.add();
		else if (userInput.compare("SEARCH") == 0)
			phonebook.search();
		else if (userInput.compare("EXIT") == 0)
			phonebook.exit();
		else {
			std::cout << "This command doesn't exist: ";
			std::cout << "please, try typping ADD, SEARCH or EXIT." << std::endl;
		}
	}
	return (0);
}
