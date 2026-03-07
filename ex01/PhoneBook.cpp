/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:45:49 by mberthou          #+#    #+#             */
/*   Updated: 2026/02/06 19:03:41 by mberthou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

void	PhoneBook::add() {
	int		indexEmptyContact = addCount++ % 8;
	Contact	&contact = listOfContact[indexEmptyContact];
	std::string	prompts[] = {
		"first name",
		"last name",
		"nickname",
		"phone number (digits only, if you please—machines are literal creatures)",
		"darkest secret (stored discreetly, though never truly forgotten)"
	};
	std::string errorMessage[] = {
		"Kindly furnish a name, if you please.",
		"Name must be furnished, I say!",
		"You must provide a moniker, pray tell",
		"That ain't no proper telephone number, give it another go, won't ya?",
		"Don't you triffle with me... Everybody has a skeleton in their closet!",
		"The file hath concluded without a newline, I say!"
	};

	for (int i = 0; i < 5; i++)
		contact.setField((Contact::Field)i, (i == 3) ? &isNumber : 0, prompts[i], errorMessage[i]);
}

void	PhoneBook::search() {
	std::string	userInput;

	std::cout << "/----------.----------.----------.----------\\" << std::endl;
	std::cout << "|  Index   |First name|Last  name| Nickname |" << std::endl;
	std::cout << "}----------+----------+----------+----------{" << std::endl;

	int i = 0;
	for (;i < ((addCount < 8) ? addCount : 8); i++) {
		listOfContact[i].displayContact(i);
	}

	std::cout << "\\----------'----------'----------'----------/" << std::endl;

	while (42) {
		std::cout << "Pray, select the contact whose particulars you desire to view:" << std::endl;
		std::cout << ">";
		std::getline(std::cin, userInput);
		if (std::cin.eof() == 1) {
			std::cin.clear();
		}
		if (userInput.compare("exit") == 0)
			break;
		int res = std::stoi(userInput) - 1;
		if (res > i || res < 0) {
			std::cout << res << std::endl;
			std::cout << "The digits ye provided be either beyond the pale or plumb incorrect." << std::endl;
			return ;
		}
		listOfContact[res].displayContactInfos();
	}
}

int	PhoneBook::exit() {
	std::cout << "Farewell, stranger!" << std::endl;
	return (0);
}

PhoneBook::PhoneBook() :
	addCount(0)
{}
