/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:00:03 by mberthou          #+#    #+#             */
/*   Updated: 2026/02/05 17:58:41 by mberthou         ###   ########.fr       */
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
		void	setField(Field index, bool (*validateField)(const std::string&),
				const std::string &prompt, const std::string &errorMessage);
		const	std::string	&getField(int index);
		void	printFixedWidthField(const std::string &text,
				std::size_t width = 10);
		void	displayContact(int i);
		void	displayContactInfos();
};

class PhoneBook {
	private :
		Contact listOfContact[8];
		int	isFieldEmpty();
		int	addCount;
	public :
		PhoneBook();
		void add();
		void search();
		int exit();
};

bool	isNumber(const std::string &s);

# endif
