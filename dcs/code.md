# C++ Mod 00

## Study resources
- https://github.com/Elli-v/42_C04_CPP_Module/blob/master/CPP_Module_00/ex01/PhoneBook.cpp
- https://velog.io/@soooh_42/42Seoul-CPP-Module-00-ex00-xv7eiqfu
- https://cplusplus.com/reference/iomanip/setw/
- https://chatgpt.com/c/4e79a76f-b1c5-45bc-9268-f699a3653aa6

## Hello World
```cpp
#include <iostream>

int main(void)
{
    char    buff[512];

    std::cout << "Hello Wolrd!" << std::endl;
    std::cout << "Digit one word: ";
    std::cin >> buff;
    std::cin >> buff;
    std::cout << "You entered: [" << buff << "]" << std::endl; 
    return (0);
}
```

## Exercício 00
```cpp
#include <iostream>

/**
 * Função do const:
 * const na linha const std::string &str indica que a função StringUppercase
 * não irá modificar a string str passada como argumento. Isso é importante
 * para garantir que a função apenas lê os dados e não os altera, 
 * proporcionando maior segurança e clareza.
 *
 * Diferença entre const std::string& str e const std::string &str:
 * Em termos de funcionalidade, const std::string& str e 
 * const std::string &str são equivalentes. 
 * Ambos indicam que str é uma referência constante para um objeto 
 * std::string. A escolha de onde colocar o espaço (std::string& vs 
 * std::string &) é puramente estilística e não afeta o comportamento
 * do código. No entanto, a convenção mais comum é const std::string &str.
 * 
 * std::string::size_type: 
 * É o tipo retornado pelo método size() de um objeto std::string.
 * Usar std::string::size_type garante portabilidade entre diferentes 
 * plataformas, já que size() retorna um tipo específico para o tamanho da
 * string naquela plataforma. 
 * converted.size(): retorna o tamanho da string converted.
*/
std::string	StringUppercase(const std::string &str)
{
	std::string	converted = str; // Cria uma copia estatica
	for (std::string::size_type i = 0; i < converted.size(); ++i)
		converted[i] = std::toupper(converted[i]);
	return (converted);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << StringUppercase(argv[i]);
			if (i < argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
```

## Exercício 01
```cpp
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
```