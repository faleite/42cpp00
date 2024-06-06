/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:12:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/06 18:44:38 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	public:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;
		Contact() : firstName(""), lastName(""), nickName(""), 
					phoneNumber(""), darkSecret("") {};
};

class PhoneBook
{
	private:
		Contact	contacts[8];
		size_t	contactIndex;
		void	addContact(size_t contactIndex);
		// bool	addContact(size_t contactIndex);
		void	listContacts(size_t contactIndex);
		void	showContact(size_t contactIndex);

	public:
		PhoneBook();
		~PhoneBook();
		void	Add();
		void	Search();
		void	printHeader();
};

# endif // PHONEBOOK_HPP