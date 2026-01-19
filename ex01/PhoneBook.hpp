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


class Contact {
	private :
		std::string	field[5];
		enum Field {
			firstName,
			lastName,
			phoneNumber,
			darkestSecret
		};
		bool	isSet;
	public :
		void	setField(std::string &field, bool (*validateField)(const std::string&),
				const std::string &prompt, const std::string &errorMessage);
		const	std::string	getField(int index);
		void	printFixedWidthField(const std::string &text,
				std::size_t width = 10);
		void	displayContact(contact &listOfContact);
		void	displayContactInfos(contact &listOfContact);
};

class PhoneBook {
	private :
		Contact listOfContact[8];
		int	isFieldEmpty();
		int	findEmptyField(Contact listOfContact[]);
	public :
		void add();
		void search();
		int exit();
};

# endif
