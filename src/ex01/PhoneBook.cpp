/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:40:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/28 21:03:03 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}
PhoneBook::~PhoneBook() { std::cout << "PhoneBook deteled" << std::endl; }

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
	if (index < 8)
		contacts[index++] = newContact;
	else
	{
		for (int i = 0; i < 7; i++)
			contacts[i] = contacts[i + 1];
		contacts[7] = newContact; 
	}
	addContact(index++);
}

/**
 * https://github.com/Elli-v/42_C04_CPP_Module/blob/master/CPP_Module_00/ex01/PhoneBook.cpp
 * https://velog.io/@soooh_42/42Seoul-CPP-Module-00-ex00-xv7eiqfu
 * https://cplusplus.com/reference/iomanip/setw/
 * https://chatgpt.com/c/4e79a76f-b1c5-45bc-9268-f699a3653aa6
 * 
*/