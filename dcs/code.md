# C++ Mod 00 
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