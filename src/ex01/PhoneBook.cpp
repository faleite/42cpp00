/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:40:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/27 20:56:32 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {};

/**
 * @brief Adds a new contact to the phone book.
 * This function adds a new contact to the phone book.
 * If there is space available in the phone book, the contact is added at
 * the next available index. If the phone book is already full, the oldest 
 * contact is removed and the new contact is added at the end.
 * 
 * @param newContact The contact to be added.
 */
void	PhoneBook::addContact(Contact &newContact)
{
	if (index < 8)
		contacts[index++] = newContact;
	else
	{
		for (int i = 0; i < 7; i++)
			contacts[i] = contacts[i + 1];
		contacts[7] = newContact; 
	}
}
