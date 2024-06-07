/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckString.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:41:32 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/07 20:55:21 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	printHeader(void)
{
	std::cout << " _________________________________________________________________" << std::endl;
	std::cout << "|                                                                 |" << std::endl;
	std::cout << "|************************ PHONEBOOK APP***************************|" << std::endl;
	std::cout << "|*****************************************************************|" << std::endl;
	std::cout << "|************************ Instruction: ***************************|" << std::endl;
	std::cout << "|Save Contact: ADD | Search Contact: SEARCH | Phonebook end: EXIT |" << std::endl;
	std::cout << "|_________________________________________________________________|" << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|";
	std::cout << std::setw(10) << "Phone num." << "|";
	std::cout << std::setw(10) << "Dark sec." << "|";
	std::cout << std::endl;
}

bool	whiteSpaces(const std::string &string)
{
	for (size_t i = 0; i < string.size(); ++i)
	{
		if (std::isspace(string[i]))
			return (true);
	}
	return (false);
}

bool	isDigit(const std::string &string)
{
	for (size_t i = 0; i < string.size(); ++i)
	{
		if (!std::isdigit(string[i]))
			return (false);
	}
	return (true);
}

std::string	checkString(std::string string, std::string msg)
{
	std::cout << msg;
	std::getline(std::cin, string);
	while (string.empty() || whiteSpaces(string))
    {
        std::cerr << "Invalid input, try again!" << std::endl;
        std::cout << msg;
        std::getline(std::cin, string);
		if (std::cin.eof())
			return ("");
    }
	return (string);
}

std::string	checkNumber(std::string string, std::string msg)
{
	std::cout << msg;
	std::getline(std::cin, string);
	while (string.empty() || !isDigit(string))
    {
        std::cerr << "Invalid input, try again!" << std::endl;
        std::cout << msg;
        std::getline(std::cin, string);
		if (std::cin.eof())
			return ("");
    }
	return (string);
}
