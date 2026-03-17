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
#include <cstdlib>

#include "PhoneBook.hpp"
#include "colours.hpp"

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
	PhoneBook::displayMenuPrompt();
}

void	PhoneBook::search() {
	std::string	userInput;

	if (addCount == 0) {
		std::cout	<< BLUE
					<< "Alas, this Directory appears to be quite empty."
					<< std::endl
					<< "Why not enter ADD to record the first contact?"
					<< RESET << std::endl;
		return ;
	}

	int lastContactIndex = PhoneBook::displayTable();

	while (42) {
		userInput = PhoneBook::askIndex();

		if (userInput == "EXIT") {
			PhoneBook::displayMenuPrompt();
			break;
		}

		if (!isNumber(userInput)) {
			std::cerr	<< RED << "The digits ye provided be either beyond the"
						<< " pale or plumb incorrect." << RESET << std::endl;
			std::cout << std::endl;
			continue;
		}

		int index;
		if (!stringToInt(userInput, index)) {
			std::cerr << RED << "Invalid index" << RESET << std::endl;
			PhoneBook::displayMenuPrompt();
			return;
		}
		index -= 1;
		if (index >= lastContactIndex || index < 0) {
			std::cerr	<< RED << "The digits ye provided be either beyond the"
						<< " pale or plumb incorrect." << RESET << std::endl;
			std::cout << std::endl;
			continue;
		}
		listOfContact[index].displayContactInfos();
	}
}

int	PhoneBook::exit() {
	std::cout	<< std::endl << BLUE << "Farewell, stranger!" << RESET
				<< std::endl;
	return (0);
}

PhoneBook::PhoneBook() :
	addCount(0)
{}
