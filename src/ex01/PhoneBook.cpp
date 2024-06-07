/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:40:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/07 16:14:32 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactIndex(0) {}
PhoneBook::~PhoneBook() { std::cout << "PhoneBook deteled!" << std::endl; }

void	PhoneBook::addContact(size_t index)
{
	Contact &contact = contacts[index];
	
	contact.firstName = checkString(contact.firstName, "First name: ");
	contact.lastName = checkString(contact.lastName, "Last name: ");
	contact.nickName = checkString(contact.nickName, "Nickname: ");
	contact.phoneNumber = checkNumber(contact.phoneNumber, "Phone number: ");
	contact.darkSecret = checkString(contact.darkSecret, "Dark secret: ");
}

/**
 * @brief Adds a new contact to the phone book.
 * This function adds a new contact to the phone book.
 * If there is space available in the phone book, the contact is added at
 * the next available index. If the phone book is already full, the oldest 
 * contact is removed and the new contact is added at the end.
 * 
 * @param newContact The contact to be added.
 */
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

void	PhoneBook::listContacts(size_t index)
{
	Contact &contact = contacts[index];

	std::cout << "|";
	std::cout << std::setw(10) << (index + 1) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.firstName) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.lastName) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.nickName) << "|";
	std::cout << std::endl;
}

void	PhoneBook::showContact(size_t index)
{
	Contact &contact = contacts[index];

	std::cout << "|";
	std::cout << std::setw(10) << (index + 1) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.firstName) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.lastName) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.nickName) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.phoneNumber) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.darkSecret) << "|";
	std::cout << std::endl;	
}

void	PhoneBook::Search(void)
{
	size_t	index(0);
	std::string line;
	
	printHeader();
	for (size_t i = 0; i < contactIndex; i++)
		listContacts(i);
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
