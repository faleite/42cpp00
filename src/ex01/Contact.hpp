/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:10:58 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/07 20:53:43 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;
	public:
		Contact();
		void		setContact(std::string first, std::string last,
					std::string nick, std::string phone, std::string secret);
		void		printContacts(size_t index);
		void		printSearchContact(size_t index);
		std::string	strlenCheck(const std::string &str);
};
