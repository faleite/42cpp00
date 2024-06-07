/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:40:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/07 20:34:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactIndex(0) {}
PhoneBook::~PhoneBook() { std::cout << "PhoneBook deteled!" << std::endl; }

void	PhoneBook::Add(void)
{
	if (contactIndex == 8)
	{
		for (size_t i = 1; i < contactIndex; i++)
			contacts[i - 1] = contacts[i];
		contactIndex--;
	}
	addContact(contactIndex++);
}

void	PhoneBook::addContact(size_t index)
{
	Contact &contact = contacts[index];
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkSecret;
	
	firstName = checkString(firstName, "First name: ");
	lastName = checkString(lastName, "Last name: ");
	nickName = checkString(nickName, "Nickname: ");
	phoneNumber = checkNumber(phoneNumber, "Phone number: ");
	darkSecret = checkString(darkSecret, "Dark secret: ");
	contact.setContact(firstName, lastName, nickName, phoneNumber, darkSecret);
}

void	PhoneBook::Search(void)
{
	size_t	index(0);
	std::string line;
	
	printHeader();
	for (size_t i = 0; i < contactIndex; i++)
		showContacts(i);
	std::cout << std::endl << "Insert index: ";
	std::getline(std::cin, line);
	std::stringstream ss(line);
	ss >> index;
	index--;
	if (contactIndex == 0)
		std::cout << "Phonebook is empty!" << std::endl;
	else if (index < 0 || index >= contactIndex)
		std::cout << "Ivalid index!" << std::endl;
	else
		showContact(index);		
}

void	PhoneBook::showContacts(size_t index)
{
	Contact &contact = contacts[index];

	contact.printContacts(index);
}

void	PhoneBook::showContact(size_t index)
{
	Contact &contact = contacts[index];

	contact.printSearchContact(index);
}
