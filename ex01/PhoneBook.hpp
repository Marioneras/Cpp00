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

enum Field = {
	firstName,
	lastName,
	phoneNumber,
	darkestSecret
}

class Contact {
	private :
		std::string	field[5];
	public :
}

class PhoneBook {
	private :
		Contact ListOfContact[8];
		int	isFieldEmpty();
		int	findEmptyField(Contact listOfContact[]);
	public :
		void add();
		void search();
		int exit();
}
