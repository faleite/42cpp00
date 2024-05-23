/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:12:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/23 20:19:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * PhoneBook Class:
 * @param array of contacts (with 8 contacts)
 * 		@brief Pode armazenar no máximo 8 contatos.
 * 		Se o usuário tentar adicionar um 9º contato,
 * 		substitua o mais antigo pelo novo
 * 		@warning "dynamic allocation is forbidden."
*/

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

/**
 * @brief Na inicialização do programa, a agenda está vazia e o usuário é
 * solicitado a inserir um dos três comandos. O programa aceita apenas ADD,
 * SEARCH e EXIT
 * @param ADD Metodo para salvar um novo contacto
 * 		@brief Se o usuário inserir este comando, ele será solicitado a inserir
 * 		as informações do novo contato, um campo por vez. Depois que todos
 * 		os campos forem preenchidos, adicione o contato à lista telefônica.
*		@brief Os campos de contato são: nome, sobrenome, apelido, número
*		de telefone e segredo mais obscuro. 
*		Um contato salvo não pode ter campos vazios
* @param SEARCH display a specific contact
*		@brief Exibe os contatos salvos como uma lista de 4 colunas:
*		índice, nome, sobrenome e apelido.
*		@brief Cada coluna deve ter 10 caracteres de largura. 
*		Um caractere de barra vertical ('|') os separa. 
*		O texto deve estar alinhado à direita. Se o texto for maior que
*		a coluna, ele deverá ser truncado e o último caractere exibível
*		deverá ser substituído por um ponto (’.’).
*		@brief Em seguida, solicite novamente ao usuário o índice da entrada
*		a ser exibido. Se o índice estiver fora do intervalo ou errado, defina
*		um comportamento relevante. Caso contrário, exiba as informações de 
*		contato, um campo por linha.
* @param EXIT The program quits and the contacts are lost forever!
*		@brief Qualquer outra entrada é descartada.
*		@brief Depois que um comando for executado corretamente, o programa 
*		aguarda outro. Ele para quando o usuário digita EXIT.
*		@brief Dê um nome relevante ao seu executável.
*/