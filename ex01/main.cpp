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
#include <cstdlib>

#include "PhoneBook.hpp"
#include "colours.hpp"

int	main() {
	std::string	userInput;
	PhoneBook	phonebook;

	std::cout	<< BLUE << "Good day to you, inquisitive caller." << std::endl
				<< std::endl << "You have opened the Amazing Phonebook, "
				<< "Edition Perpetual — once a humble book of paper and ink, "
				<< "now enlivened by currents unseen." << std::endl
				<< std::endl
				<< "I stand ready to serve, faithfully and without gossip."
				<< std::endl
				<< "Should you wish to inscribe a new name upon my ever-growing"
				<< " pages, enter ADD." << std::endl
				<< "If you seek a particular party already recorded, enter SEARCH."
				<< std::endl
				<< "And should your business here be concluded, "
				<< "you may close my covers by entering EXIT." << std::endl
				<< std::endl
				<< "Pray tell, how may I be of assistance?" << RESET
				<< std::endl;

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
				std::cerr	<< RED << "This command doesn't exist: "
							<< "please, try typping ADD, SEARCH or EXIT."
							<< RESET << std::endl;
			}
		}
		else {
			if (std::cin.eof()) {
				std::cout << std::endl;
				std::cerr << RED << "Ctrl+D entered" << RESET << std::endl;
				std::exit(EXIT_FAILURE);
			}
			else {
				std::cout << std::endl;
				std::cerr << RED << "Input error!" << RESET << std::endl;
				break;
			}
		}
	}
	return (0);
}
