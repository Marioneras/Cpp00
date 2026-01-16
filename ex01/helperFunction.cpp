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
	std::cout << "Enter your "<< prompt << ": ";
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
