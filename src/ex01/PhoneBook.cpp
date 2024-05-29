/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:40:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/29 21:03:52 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	strlenCheck(std::string str);
PhoneBook::PhoneBook() : contactIndex(0) {}
// PhoneBook::~PhoneBook() { std::cout << "PhoneBook deteled" << std::endl; }

void	PhoneBook::addContact(size_t index)
{
	Contact &contact = contacts[index];
	
	std::cout << "First name: ";
	std::cin >> contact.firstName;
	std::cout << "Last name: ";
	std::cin >> contact.lastName;
	std::cout << "Nickname: ";
	std::cin >> contact.nickName;
	std::cout << "Phone number: ";
	std::cin >> contact.phoneNumber;
	std::cout << "Dark secret: ";
	std::cin >> contact.darkSecret;
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
	
	PhoneBook::printHeader();
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|";
	std::cout << std::endl;
	for (size_t i = 0; i < contactIndex; i++)
		listContacts(i);
	std::cout << std::endl << "Insert index: ";
	std::cin >> index;
	index--;
	if (contactIndex == 0)
		std::cout << "Phonebook is empty!" << std::endl;
	else if (index < 0 || index > contactIndex)
		std::cout << "Ivalid index!" << std::endl;
	else
		showContact(index);		
}

std::string	strlenCheck(std::string str)
{
	if (str.length() > 9)
	{
		str = str.substr(0, 9);
		str = str + ".";
	}
	return (str);
}

void	PhoneBook::printHeader(void)
{
	std::cout << " _________________________________________________________________" << std::endl;
	std::cout << "|                                                                 |" << std::endl;
	std::cout << "|************************ PHONEBOOK APP***************************|" << std::endl;
	std::cout << "|*****************************************************************|" << std::endl;
	std::cout << "|************************ Instruction: ***************************|" << std::endl;
	std::cout << "|Save Contact: ADD | Search Contact: SEARCH | Phonebook end: EXIT |" << std::endl;
	std::cout << "|_________________________________________________________________|" << std::endl;
}

/**
 * https://github.com/Elli-v/42_C04_CPP_Module/blob/master/CPP_Module_00/ex01/PhoneBook.cpp
 * https://velog.io/@soooh_42/42Seoul-CPP-Module-00-ex00-xv7eiqfu
 * https://cplusplus.com/reference/iomanip/setw/
 * https://chatgpt.com/c/4e79a76f-b1c5-45bc-9268-f699a3653aa6
 * 
*/