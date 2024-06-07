/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:54:38 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/07 20:41:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string command;
	
	printHeader();		
	while(true)
	{
		std::cout << std::endl << "INSERT COMMAND: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (0);
		std::cout << std::endl;
		if (command == "ADD")
			phonebook.Add();
		else if (command == "SEARCH")
			phonebook.Search();
		else if (command == "EXIT")
			return (0);
		else
			std::cerr << "---------- INVALID COMMAND ----------";
	}
}
