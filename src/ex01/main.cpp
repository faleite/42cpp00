/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:54:38 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/29 19:31:25 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string command;
	
	phonebook.printHeader();		
	while(true)
	{
		std::cout << std::endl << "INSERT COMMAND: ";
		std::cin >> command, std::cout << std::endl;
		if (command == "ADD" || command == "add")
			phonebook.Add();
		else if (command == "SEARCH" || command == "search")
			phonebook.Search();
		else if (command == "EXIT" || command == "exit")
			return (0);
		else
			std::cerr << "---------- INVALID COMMAND ----------" << std::endl;
		/*
		* A função `cin.clear()` é usada para limpar o estado de erro do fluxo
		* de entrada. Por exemplo, se você tentar ler um número inteiro do
		* fluxo de entrada e o usuário digitar uma string, o fluxo de entrada
		* entrará em um estado de erro e todas as futuras leituras falharão até
		* que você limpe o estado de erro. cin.clear() limpa esse estado de erro.
		*/
		std::cin.clear();
		
		/*
		 * A função std::cin.ignore(n, delim): é usada para ignorar (descartar)
		 * até `n` caracteres no fluxo de entrada ou até que um caractere `delim`.
		 * No contexto deste código, essa função é usada para descartar
		 * o restante da linha de entrada depois de ler o comando do usuário.
		 * Isso é útil se o usuário digitar mais do que um comando na mesma
		 * linha. Por exemplo, se o usuário digitar "ADD extra", 
		 * std::cin >> command; lerá apenas "ADD" e " extra" permanecerá 
		 * no fluxo de entrada. Se você não descartar o restante da linha,
		 * a próxima vez que você tentar ler um comando, você lerá " extra" 
		 * em vez de esperar que o usuário digite um novo comando.
		*/
		std::cin.ignore(1000, '\n');

		/*
		 * Em um programa interativo, std::cin.eof() retornará true
		 * se o usuário fechar a entrada padrão 
		 * Por exemplo: pressionando Ctrl+D no terminal do Unix.
		 * Se você está lendo de um arquivo e atinge o fim do arquivo (EOF)
		*/
		if (std::cin.eof())
			return (0);
	}
}
