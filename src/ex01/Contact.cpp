/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:13:27 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/07 20:38:53 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() : firstName(""), lastName(""), nickName(""), 
						phoneNumber(""), darkSecret("") {};

void	Contact::setContact(std::string first, std::string last, std::string nick,
			std::string phone, std::string secret)
{
	this->firstName = first;
	this->lastName = last;
	this->nickName = nick;
	this->phoneNumber = phone;
	this->darkSecret = secret;
}

std::string	Contact::strlenCheck(const std::string &str)
{
	if (str.length() > 9)
	{
		return (str.substr(0, 9) + ".");
	}
	return (str);
}

void	Contact::printContacts(size_t index)
{	
	std::cout << "|";
	std::cout << std::setw(10) << (index + 1) << "|";
	std::cout << std::setw(10) << strlenCheck(firstName) << "|";
	std::cout << std::setw(10) << strlenCheck(lastName) << "|";
	std::cout << std::setw(10) << strlenCheck(nickName) << "|";
	std::cout << std::endl;
}

void	Contact::printSearchContact(size_t index)
{
	std::cout << "|";
	std::cout << std::setw(10) << (index + 1) << "|";
	std::cout << std::setw(10) << strlenCheck(firstName) << "|";
	std::cout << std::setw(10) << strlenCheck(lastName) << "|";
	std::cout << std::setw(10) << strlenCheck(nickName) << "|";
	std::cout << std::setw(10) << strlenCheck(phoneNumber) << "|";
	std::cout << std::setw(10) << strlenCheck(darkSecret) << "|";
	std::cout << std::endl;	
}
