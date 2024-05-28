/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:28:20 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/28 20:48:22 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * O operador this-> é usado para acessar membros da classe dentro de seus
 * próprios métodos. this é um ponteiro que aponta para o objeto que
 * invocou o método.
 * Você normalmente usa this-> quando tem uma variável local ou um parâmetro
 * com o mesmo nome que uma variável membro e você precisa distinguir entre
 * elas. Por exemplo:
 * void Contact::setFirstName(std::string firstName)
 * {
 * // Aqui, "this->firstName" se refere à variável membro, 
 * // e "firstName" se refere ao parâmetro.
 *     this->firstName = firstName;
 * }
*/
// void Contact::setContact(std::string (&arr)[5])
// {
// 	this->firstName = arr[0];
// 	this->lastName = arr[1];
// 	this->nickName = arr[2];
// 	this->phoneNumber = arr[3];
// 	this->darkSecret = arr[4];
// }

