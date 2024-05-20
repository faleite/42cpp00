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

## Member attributes and member function
- `Member attributes` são variáveis que são declaradas dentro de uma classe e e pode usar em uma instância desta classe. Eles são acessíveis a qualquer função que pertença à classe.
- `Member functions` são funções que são declaradas dentro de uma classe. Uma função tem sua definição ou protótipo dentro da definição da classe como qualquer outra variável. Ele opera em qualquer objeto da classe da qual é membro e tem acesso a todos os membros de uma classe desse objeto.
***Exemplo:***
```cpp
#include <iostream>

using namespace std;

class Box {
   public:
      double length;         // Length of a box
      double breadth;        // Breadth of a box
      double height;         // Height of a box

      // Member functions declaration
      double getVolume(void);
      void setLength( double len );
      void setBreadth( double bre );
      void setHeight( double hei );
};

// Member functions definitions
double Box::getVolume(void) {
   return length * breadth * height;
}

void Box::setLength( double len ) {
   length = len;
}
void Box::setBreadth( double bre ) {
   breadth = bre;
}
void Box::setHeight( double hei ) {
   height = hei;
}

// Main function for the program
int main() {
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);

   // box 2 specification
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);

   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;
   return 0;
}
```
```bash
# Output
Volume of Box1: 210
Volume of Box2: 1560
```

## This 'pointer' (the keyword self)
- `this` é um ponteiro que aponta para o objeto atual. `this` é um ponteiro constante que mantém o endereço do objeto atual. Em C++, cada objeto obtém sua própria cópia dos membros dos dados e todos os objetos compartilham uma única cópia das funções-membro. Para se referir à sua instância atual, use o ponteiro de instância especial `this`.
- Uma função membro possui apenas uma cópia e é usada por vários objetos. Como os membros de dados adequados são acessados ​​e atualizados? O compilador fornece um ponteiro implícito junto com os nomes das funções como `this`.
- referência: [***this poniter in C++***](https://www.shiksha.com/online-courses/articles/this-pointer-in-c/)

## Initialization list
- As listas de inicialização em C++ são uma maneira de inicializar os membros de dados de uma classe. Elas são usadas principalmente em construtores para inicializar várias propriedades de um objeto.

***Exemplo.class.hpp***
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:
	//attributes
	char a1;
	int a2;
	float a3;

	Sample(char p1, int p2, float p3);
	~Sample(void);
};

#endif
```
***Exemplo.class.cpp***
```cpp
#include <iostream>
#include "Sample.class.hpp"

//initialise the attributes in a class
Sample::Sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) // initialisation list
{
	std::cout << "Constructor called" << std::endl;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}
```
***main.cpp***
```cpp
#include <iostream>
#include "Sample.class.hpp"

int	main(void)
{
	Sample	instance('a', 42, 4.2f);

	return (0);
}
```
```bash
# Output
Constructor called
this->a1 = a
this->a2 = 42
this->a3 = 4.2
Destructor called
```

## Const
- `const` é uma palavra-chave em C++ que é usada para tornar uma variável constante. Uma variável constante é uma variável cujo valor não pode ser alterado. Uma variável constante deve ser inicializada no momento da declaração.
- `const data menbers` deve ser inicializado usando `initialization list`. Nenhuma memória é alocada separadamente para o membro de dados const. Ele está dobrado na tabela de símbolos e por isso precisamos inicializá-lo
- `const data members` também é um construtor de cópia. Não precisamos ligar para o operador de atribuição, o que significa que evitamos uma operação extra.
- Quanto maior for o seu código conste read only, mais robusto será o seu código a longo prazo.
- referência: [***const in C++***](https://pt.stackoverflow.com/questions/79909/declara%C3%A7%C3%A3o-const-no-final-de-fun%C3%A7%C3%A3o-em-c-e-const-antes-do-argumento-no-m%C3%A9todo)

***Exemplo: Sample.class.hpp***
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample
{
public:

	float const pi;
	int qd;

	Sample(float const f);
	~Sample(void);

	// const entre ) e ; -> a instância da classe nunca será alterada
	void bar(void) const;
};

#endif
```
***Exemplo: Sample.class.cpp***
```cpp
#include <iostream>
#include "Sample.class.hpp"

// it's not assigning f value to pi attribute
// it's initialising pi attribute to the f value
Sample::Sample(float const f) : pi(f), qd(42) {

	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return;
}

// this is central to CPP
// define const when your member function should never be changed in the \
// current instance of your class
void	Sample::bar(void) const {

	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;

	// this assignment below won't work, as it's a const function
	// this->qd = 0;
	return;
}
```
***Exemplo: main.cpp***
```cpp
#include <iostream>
#include "Sample.class.hpp"

int main() {

	Sample instance(3.14f);

	instance.bar();

	return (0);
}
```
```bash
# Output
Constructor called
this->pi = 3.14
this->qd = 42
Destructor called
```

## Visibility
- `Visibility` é uma propriedade de um membro de uma classe que determina se ele pode ser acessado de fora da classe. Existem três tipos de visibilidade em C++: `public`, `private` e `protected`.
- `public e private` permitirá que você controle o encapsulamento dos membros da classe. Isso significa que os atributos e funções-membro só serão visíveis de dentro da classe ou de fora.
- `Public` atributos e funções podem ser acessados ​​dentro e fora da classe.
- `Private` atributos e funções só são acessíveis de dentro da classe. Esses atributos e funções são perfeitamente invisíveis e inacessíveis de fora da classe, caso contrário, o código não será compilado.
- `Tenha em mente`: para atributos ou funções que não têm nada a ver com o usuário, mantenha-os privados na classe. Ao planejar uma classe, pense sempre no que manter internamente ou expor para fora.
- referência: [***Visibility in C++***](https://www.scaler.com/topics/private-public-and-protected-are-all/)

***Exemplo: Sample.class.hpp***
```cpp
#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample
{
public:

	int publicFoo;

	// need to consider what makes more sense to place the constructor \
	// and destructor in private or public
	Sample(void);
	~Sample(void);

	void publicBar(void) const;

private:

	// use _ prefix for all private identifier
	// it gives reader a quick idea of which is public or private
	int _privateFoo;

	void _privateBar(void) const;
};

#endif
```
***Exemplo: Sample.class.cpp***
```cpp
#include <iostream>
#include "Sample.class.hpp"

// this can also be written with initialisation list
Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;

	this->publicFoo = 0;
	std::cout << "this->publicFoo = " << this->publicFoo <<std::endl;
	this->_privateFoo = 0;
	std::cout << "this->_privateFoo = " << this->_privateFoo <<std::endl;

	this->publicBar();
	this->_privateBar();

	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::publicBar(void) const
{
	std::cout << "Member function publicBar called" << std::endl;
	return;
}

void	Sample::_privateBar(void) const
{
	std::cout << "Member function _privateBar called" << std::endl;
	return;
}
```

***Exemplo: main.cpp***
```cpp
#include <iostream>
#include "Sample.class.hpp"

int	main(void)
{
	Sample	instance;

	instance.publicFoo = 42;
	std::cout << "instance.publicFoo = " << instance.publicFoo << std::endl;
	// compilation error when you want to access private attributes
	// instance._privateFoo = 42;
	// std::cout << "instance._privateFoo = " << instance._privateFoo << std::endl;

	instance.publicBar();
	// compilation error when you want to access private function
	// instance._privateBar();

	return (0);
}
```
```bash
# Output
Constructor called
# inside the constructor: can access both private and public attributes / functions
this->publicFoo = 0
this->_privateFoo = 0
Member function publicBar called
Member function _privateBar called
# outside the constructor: can only access public attributes / functions
instance.publicFoo = 42
Member function publicBar called
Destructor called
```

## Class vs struct
- `Class` e `struct` são usados para definir classes em C++. A única diferença entre `class` e `struct` é que a visibilidade padrão de membros e bases de classe é `private` em `class` e `public` em `struct`.
- Uma classe também pode conter funções (chamadas `methods` em C++). Os atributos e métodos dos membros ficam ocultos do mundo externo, a menos que sua declaração siga um rótulo público
- Métodos especiais (`constructore` `destructor`) em C++. Eles são executados automaticamente quando um objeto (uma instância da classe) é criado e destruído.
- Operadores para trabalhar no novo tipo de dados podem ser definidos usando métodos especiais (`member functions`)
- Uma classe pode ser usada como base para a definição de outra (`heranca`)
- Declarar uma variável do novo tipo (um objeto) requer apenas o nome da classe. A palavra-chave `class` não é obrigatória.
