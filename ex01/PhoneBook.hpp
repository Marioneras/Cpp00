/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:00:03 by mberthou          #+#    #+#             */
/*   Updated: 2025/11/21 20:26:37 by mberthou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <cstring>


class Contact {
	private :
		std::string	field[5];
	public :
		enum Field {
			firstName,
			lastName,
			nickname,
			phoneNumber,
			darkestSecret
		};
		bool	isSet;
		void	setField(Field index, bool (*validateField)(const std::string&),
				const std::string &prompt, const std::string &errorMessage);
		const	std::string	&getField(int index);
		void	printFixedWidthField(const std::string &text,
				std::size_t width = 10);
		void	displayContact(int i);
		void	displayContactInfos(Contact &listOfContact);
};

class PhoneBook {
	private :
		Contact listOfContact[8];
		int	isFieldEmpty();
		int	findEmptyField();
	public :
		void add();
		void search();
		int exit();
};

bool	isNumber(const std::string &s);

# endif
