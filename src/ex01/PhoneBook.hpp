/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:12:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/07 20:34:37 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		size_t	contactIndex;
		void	addContact(size_t contactIndex);
		void	showContacts(size_t contactIndex);
		void	showContact(size_t contactIndex);

	public:
		PhoneBook();
		~PhoneBook();
		void	Add();
		void	Search();
};

bool		whiteSpaces(const std::string &string);
bool		isDigit(const std::string &string);
void		printHeader(void);
std::string	checkString(std::string string, std::string msg);
std::string	checkNumber(std::string string, std::string msg);

# endif // PHONEBOOK_HPP