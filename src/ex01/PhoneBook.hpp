/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:12:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/27 20:58:46 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

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
		int		index;
		void	addContact(Contact &newContact);

	public:
		PhoneBook();
		void	printContacts();

};

# endif // PHONEBOOK_HPP