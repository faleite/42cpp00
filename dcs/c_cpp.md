# From C to C++98
***Resumo de conceitos básicos de C/C++98***
## Nova forma de instanciar variáveis:
```cpp
string var("myvariable");
```

 ## Operador condicional ( ? )
`condição? resultado1: resultado2`
  
  *Se a condição for verdadeira, a expressão retornará resultado1 , se não for, retornará resultado2 .*

***Exemplo:***
```cpp
7==5 ? 4 : 3     // returns 3, since 7 is not equal to 5.
7==5+2 ? 4 : 3   // returns 4, since 7 is equal to 5+2.
5>3 ? a : b      // returns the value of a, since 5 is greater than 3.
a>b ? a : b      // returns whichever is greater, a or b. 
```

## `iostream` saida e entrada padrão
   * `cin` para pegar linhas inteiras do teclado recomendado da lib `string`:
```cpp
#include <iostream>
#include <string>
getline (cin, mystring);
```

## Classe `stringstream` da `<sstring>` 
* *para operações de extração ou inserção de/para strings*
***Exemplo:***
```cpp
// Convertendo string em inteiro
#include <sstream>
string mystring("1024");
int myint;
stringstream(mystring) >> myint
```

***Exemplo stringstream/getline***
```cpp
// stringstreams
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main ()
{
  string mystr;
  float price=0;
  int quantity=0;

  cout << "Enter price: ";
  getline (cin,mystr);
  stringstream(mystr) >> price;
  cout << "Enter quantity: ";
  getline (cin,mystr);
  stringstream(mystr) >> quantity;
  cout << "Total price: " << price*quantity << endl;
  return 0;
}
```
```bash
# saída
Enter price: 22.25
Enter quantity: 7
Total price: 155.75
```

## *Loop do-while*
* Sua funcionalidade é exatamente a mesma do loop while, exceto que a condição no loop do-while é avaliada após a execução da instrução em vez de antes, garantindo pelo menos uma execução da instrução mesmo que a condição nunca seja atendida. Por exemplo, o programa de exemplo a seguir ecoa qualquer número inserido até que você insira 0 .
```cpp

// number echoer

#include <iostream>
using namespace std;

int main ()
{
  unsigned long n;
  do {
    cout << "Enter number (0 to end): ";
    cin >> n;
    cout << "You entered: " << n << "\n";
  } while (n != 0);
  return 0;
}
```

```bash
# Output
Enter number (0 to end): 12345
You entered: 12345
Enter number (0 to end): 160277
You entered: 160277
Enter number (0 to end): 0
You entered: 0
```

## [switch](https://cplusplus.com/doc/oldtutorial/control/)
* O comando switch é uma maneira alternativa de encadear várias instruções if-else que são selecionadas com base no valor de uma única variável inteira. A sintaxe do comando switch é a seguinte:
```cpp
switch example     |if-else equivalent
-------------------|-----------------------
```cpp 
switch (x) {       | if (x == 1) {
  case 1:          |  cout << "x is 1";
  cout << "x is 1";| else if (x == 2)
  break;           |  cout << "x is 2";
  case 2:          | else
  cout "x is 2";   |  cout << "value of x unknown";
  break;           |}
  default:         |
  cout << "value of x unknown";
}
```

```cpp
switch (x) {
  case 1:
  case 2:
  case 3:
    cout << "x is 1, 2 or 3";
    break;
  default:
    cout << "x is not 1, 2 or 3";
}
```

## Data structures
* Estruturas de dados são um recurso que pode ser utilizado para representar bancos de dados, principalmente se considerarmos a possibilidade de construção de arrays delas:
```cpp
// array of structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define N_MOVIES 3

struct movies_t {
  string title;
  int year;
} films [N_MOVIES];

void printmovie (movies_t movie);

int main ()
{
  string mystr;
  int n;

  for (n=0; n<N_MOVIES; n++)
  {
    cout << "Enter title: ";
    getline (cin,films[n].title);
    cout << "Enter year: ";
    getline (cin,mystr);
    stringstream(mystr) >> films[n].year;
  }

  cout << "\nYou have entered these movies:\n";
  for (n=0; n<N_MOVIES; n++)
    printmovie (films[n]);
  return 0;
}

void printmovie (movies_t movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}
```
```bash
# Output
Enter title: The Matrix
Enter year: 1999
Enter title: The Matrix Reloaded
Enter year: 2003
Enter title: The Matrix Revolutions
Enter year: 2003

You have entered these movies:
The Matrix (1999)
The Matrix Reloaded (2003)
The Matrix Revolutions (2003)
```

## Resumo de possíveis combinações de ponteiros e membros de estrutura:
Expressão |O que é avaliado |Equivalente
----------|-----------------|------------
a.b	 |Membro b do objeto a |	
a->b |Membro b do objeto apontado por a |(*a).b
*a.b |Valor apontado pelo membro b do objeto a |*(a.b)

## [Union](https://cplusplus.com/doc/oldtutorial/other_data_types/)

## [`setw()` da lib `<iomanip>`](https://cplusplus.com/reference/iomanip/setw/)
- `setw()` Define a largura (width) do campo a ser usada nas operações de saída. Usada para definir a largura do campo de saída para o próximo elemento a ser exibido no stream (como `std::cout`). Ele garante que a saída ocupe pelo menos a largura especificada, preenchendo com espaços em branco, se necessário.
