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

std::bool	isNumber(const std::string &s) {
	return (std::ranges::all_of(s.begin(), s.end(),
		[](char c) { return isdigit(c) != 0; }));
}

int	findEmptyField(contact *contact)
{
	static int i = -1;

	if (i < 7)
		i++;
	else
		i = -1;
	return (i);
}

void	setField(std::string &field, bool (*validateField)(const std::string&),
		const std::string &prompt, const std::string &errorMessage) {
	std::cout << "Inscribe thy given "<< prompt << ": ";
	string	userInput;
	getline(std::cin, userInput);
	if (std::cin.gcount() == 0)
		throw std::exception(errorMessage);
	if (validateField) {
		if (validateField(userInput))
			field = userInput;
		else
			throw std::exception(errorMessage);
	}
	else
		field = userInput;
}

const std::string	getField(int index) {
	if (index > 4)
		throw std::exception("out of range");
	return ((const)field[index]);
}

void	printFixedWidthField(const std::string &text, std::size_t width) {
	for (int i = 0, i < 9; i++)
		std::cout << text[i];
	if (text[i + 1])
		std::cout << ".";
	else
		std::cout << text[i];
}

void	displayContact(contact &listOfContact) {
	std::string contactField[5];

	for (int i = 0, i < 5; i++)
		contactField[i] = listOfContact.getField(i);

}

void	displayContactInfos(contact &listOfContact) {

}
