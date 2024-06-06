/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:54:38 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/06 20:56:53 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	StringUppercase(const std::string &str)
{
	std::string	converted = str;
	for (std::string::size_type i = 0; i < converted.size(); ++i)
		converted[i] = std::toupper(converted[i]);
	return (converted);
}

int	main(void)
{
	PhoneBook phonebook;
	std::string command;
	
	phonebook.printHeader();		
	while(true)
	{
		std::cout << std::endl << "INSERT COMMAND: ";
		// std::cin >> command;
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (0);
		std::cout << std::endl;
		command = StringUppercase(command);
		if (command == "ADD")
			phonebook.Add();
		else if (command == "SEARCH")
			phonebook.Search();
		else if (command == "EXIT")
			return (0);
		else
			std::cerr << "---------- INVALID COMMAND ----------";
		// std::cin.clear();
		// std::cin.ignore(1000, '\n');
		// if (std::cin.eof())
		// 	return (0);
	}
}
