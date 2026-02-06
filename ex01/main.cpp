/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:37:32 by mberthou          #+#    #+#             */
/*   Updated: 2026/02/05 17:45:05 by mberthou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

int	main() {
	std::string	userInput;
	PhoneBook	phonebook;

	std::cout << "Good day to you, inquisitive caller." << std::endl;
	std::cout << "You have opened the Amazing Phonebook,";
	std::cout << "Edition Perpetual—once a humble book of paper and ink,";
	std::cout << "now enlivened by currents unseen." << std::endl;
	std::cout << "I stand ready to serve, faithfully and without gossip." << std::endl;
	std::cout << "Should you wish to inscribe a new name upon my ever-growing pages, enter ADD." << std::endl;
	std::cout << "If you seek a particular party already recorded, enter SEARCH." << std::endl;
	std::cout << "And should your business here be concluded, you may close my covers by entering EXIT." << std::endl;
	std::cout << "Pray tell, how may I be of assistance?" << std::endl;

	while (42) {
		if (std::getline(std::cin, userInput)) {
			if (userInput.compare("ADD") == 0)
				phonebook.add();
			else if (userInput.compare("SEARCH") == 0)
				phonebook.search();
			else if (userInput.compare("EXIT") == 0) {
				phonebook.exit();
				break;
			}
			else {
				std::cout << "This command doesn't exist: ";
				std::cout << "please, try typping ADD, SEARCH or EXIT." << std::endl;
			}
		}
		else {
			if (std::cin.eof()) {
				std::cin.clear();
				continue;
			}
			else {
				std::cerr << "Input error!" << std::endl;
				break;
			}
		}
	}
	return (0);
}
