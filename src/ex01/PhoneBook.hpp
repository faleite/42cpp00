/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:12:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/29 20:03:53 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

/**
 * Contact Class:
 * @brief Signifique um contato da lista telefônica. 
 * No seu código, a lista telefônica deve ser instanciada como uma instância
 * da classe PhoneBook. A mesma coisa para os contatos.
 * Cada um deles deve ser instanciado como uma instância da classe Contact.
 * Você é livre para criar as classes como quiser, mas lembre-se de que
 * tudo o que sempre será usado dentro de uma classe é privado e que
 * tudo o que pode ser usado fora de uma classe é público.
*/
class Contact
{
	public:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;
		Contact() : firstName(""), lastName(""), nickName(""), 
					phoneNumber(""), darkSecret("") {};
		
		// void	setContact(std::string (&arr)[5]);
		// void	printContact();
		// void	printPhoneBook();
	
};

/**
 * PhoneBook Class:
 * @param array of contacts (with 8 contacts)
 * 		@brief Pode armazenar no máximo 8 contatos.
 * 		Se o usuário tentar adicionar um 9º contato,
 * 		substitua o mais antigo pelo novo
 * 		@warning "dynamic allocation is forbidden."
*/
class PhoneBook
{
	private:
		Contact	contacts[8];
		size_t	contactIndex;
		void	addContact(size_t contactIndex);
		void	listContacts(size_t contactIndex);
		void	showContact(size_t contactIndex);

	public:
		PhoneBook();
		// ~PhoneBook();
		void	Add();
		void	Search();
		void	printHeader();
};


# endif // PHONEBOOK_HPP