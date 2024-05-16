 # CPP 00
 
 ## Namespaces
- **Namespaces** são usados para organizar o código em grupos lógicos e evitar conflitos de nomes em grandes projetos. Eles permitem que você defina um escopo que contém identificadores (nomes de variáveis, tipos, funções, etc.) de forma que esses identificadores não colidam com nomes iguais definidos em outros escopos ou namespaces. Isso é particularmente útil em projetos grandes ou ao utilizar várias bibliotecas que podem ter definido os mesmos nomes para suas funções ou variáveis.
- Todas as entidades incluídas no `C++ standard library` estão incluídas no stdnamespace
- No entanto, `using namespace std` é considerada uma má prática, pois importa todo o `std` namespace para o namespace atual do programa. É melhor usar o operador de resolução de escopo para acessar a entidade específica (como `std::cout`)

***Exemplo 1***
```cpp
int	gl_var = 1;
int	f(void) {return 2;}

namespace	Foo {
	int	gl_var = 3;
	int	f(void) {return 4;}
}

namespace	Bar {
	int 	gl_var = 5;
	int	f(void) {return 6;}
}

// use namespace aliasing to keep a shorter and more expressive syntax
// :: scope resolution operator
namespace 	Muf = Bar;

int	main(void){
	printf("gl_var:			[%d]\n", gl_var);
	printf("f():			[%d]\n\n", f());

	//exactly the same as above (global scope)
	printf("::gl_var:		[%d]\n", ::gl_var);
	printf("::f():			[%d]\n\n", ::f());

	printf("Foo::gl_var:		[%d]\n", Foo::gl_var);
	printf("Foo::f():		[%d]\n\n", Foo::f());

	printf("Bar::gl_var:		[%d]\n", Bar::gl_var);
	printf("Bar::f():		[%d]\n\n", Bar::f());

	printf("Muf::gl_var:		[%d]\n", Muf::gl_var);
	printf("Muf::f():		[%d]\n\n", Muf::f());

	return (0);
}
```
```bash
# Output
gl_var:			[1]
f():			[2]

::gl_var:		[1]
::f():			[2]

Foo::gl_var:	[3]
Foo::f():		[4]

Bar::gl_var:	[5]
Bar::f():		[6]

Muf::gl_var:	[5]
Muf::f():		[6]
```

***Exemplo 2***
```cpp
#include <iostream>

// Definição do namespace
namespace meuNamespace {
      int valor = 5;
    int soma(int a, int b) {
          return a + b;
    }
}
// Uso do namespace
int main() {
    // Acesso ao conteúdo do namespace usando o operador de escopo (::)
    int resultado = meuNamespace::soma(3, 4);
    std::cout << "Resultado: " << resultado << std::endl; // Saída: Resultado: 7
    std::cout << "Valor: " << meuNamespace::valor << std::endl; // Saída: Valor: 5
    return 0;
}
```

## Stdio streams
- `iostream` é uma biblioteca padrão do C++ que fornece objetos de fluxo de entrada e saída.
- Streams atua como intermediário entre os programas e os dispositivos IO reais. Isso libera os programadores de lidar com os dispositivos reais.
- `std` é um namespace que contém todos os objetos e funções da biblioteca padrão do C++. presentes em `iostream`.
- `::` é o operador de resolução de escopo que é usado para acessar os membros de um namespace.
- `cin` é um objeto de fluxo de entrada que é usado para ler dados do console. `>>` é o operador de extração que é usado para ler dados do console.
- `cout` é um objeto de fluxo de saída que é usado para exibir dados no console. `<<` é o operador de inserção que é usado para exibir dados no console.
- referência: [***iostream***](https://www.cplusplus.com/reference/iostream/)

```cpp
#include <iostream>

int main(void)
{
	char buff[512];

	std::cout << "Hello World!" << std::endl;
	std::cout << "Input a word: ";
	std::cin >> buff;
	std::cout << "You entered: [" << buff << "]" << std::endl;
	return 0;
}
```

## Class and instance
- C++ é uma linguagem de programação orientada a objetos. Um objeto é criado a partir de uma classe. Tudo em C++ está associado a classes e objetos, junto com seus atributos( variables) e métodos( functions)
- Uma classe é uma estrutura de dados que contém dados e funções que operam nesses dados. Uma classe é como um plano para uma casa. Define o que a casa terá, mas não é a casa em si.
- Uma instância é um objeto de uma classe. Uma classe é como um plano para uma casa e uma instância é a casa real.
- `class` é uma palavra-chave que é usada para definir uma classe em C++. `public` é uma palavra-chave que é usada para especificar o acesso dos membros da classe. `private` é uma palavra-chave que é usada para especificar o acesso dos membros da classe.
- `~` é um operador de destruição que é usado para destruir um objeto.
- `Constructors` e `destructors` são funções-membro especiais de classes usadas para construir e destruir objetos de classe.
 - `Constructor` pode envolver alocação de memória e inicialização de objetos. 
  - `Destructor` pode envolver limpeza e desalocação de memória para objetos.
- Como outras funções-membro, construtores e destruidores são declarados em uma declaração de classe. Eles podem ser definidos inline ou externos à declaração da classe.
- `Constructor` e `destructor` não tem um tipo de retorno.
- O compilador `automatically` chama construtores ao definir objetos de classe e chama destruidores quando os objetos de classe saem do escopo.

***Exemplo: Sample.class.hpp***
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class	Sample
{
public:

	Sample(void); // CPP use the name of the class for constructor
	~Sample(void); // and the name of the class for destructor
}; // don't forget to end with semicolon

#endif
```
***Exemplo: Sample.class.cpp***
```cpp
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
```
***Exemplo: main.cpp***
```cpp
#include "Sample.class.hpp"

int	main(void)
{
	// the line below instantiate an instance
	// code in constructor will also run (to initialise data for instance)
	Sample	instance;
	return (0);
	// destructor is called when the instance goes out of scope
}
```
```bash
# Output
Constructor called
Destructor called
```	