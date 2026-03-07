/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:37:32 by mberthou          #+#    #+#             */
/*   Updated: 2026/02/06 18:12:43 by mberthou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"
#include "colours.hpp"

int	main() {
	std::string	userInput;
	PhoneBook	phonebook;

	std::cout << BLUE << "Good day to you, inquisitive caller." << std::endl;
	std::cout << "You have opened the Amazing Phonebook,";
	std::cout << "Edition Perpetual — once a humble book of paper and ink,";
	std::cout << "now enlivened by currents unseen." << std::endl;
	std::cout << "I stand ready to serve, faithfully and without gossip." << std::endl;
	std::cout << "Should you wish to inscribe a new name upon my ever-growing pages, enter ADD." << std::endl;
	std::cout << "If you seek a particular party already recorded, enter SEARCH." << std::endl;
	std::cout << "And should your business here be concluded, you may close my covers by entering EXIT." << std::endl;
	std::cout << "Pray tell, how may I be of assistance?" << RESET << std::endl;

	while (42) {
		std::cout << "> ";
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
				std::cerr	<< RED << "This command doesn't exist: ";
				std::cerr	<< "please, try typping ADD, SEARCH or EXIT."
							<< RESET << std::endl;
			}
		}
		else {
			if (std::cin.eof()) {
				std::cin.clear();
				continue;
			}
			else {
				std::cerr << RED << "Input error!" << RESET << std::endl;
				break;
			}
		}
	}
	return (0);
}
