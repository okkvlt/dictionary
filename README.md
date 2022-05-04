# Dictonary

Biblioteca em C para simular os dicionários do Python.

## ▪ Importação

Para utilizar a biblioteca, é preciso importá-la para o arquivo do seu projeto.

```c
#include "dict.h"
```

## ▪ Criação de Dicionário

Tendo importado a biblioteca, um dicionário pode ser criado passando a função `create_dict()` para uma variável do tipo _No *_.

```python
No *dicionario = create_dict();
```

## ▪ Print do Dicionário

Também é possível printar o dicionário completo utilizando a função `show_dict()`. Essa função é do tipo _void_ e não retornará nada.

Sintaxe:

```c
void show_dict(No *dicionario);
```

Exemplo: 

```python
show_dict(dicionario);
```

Retorno:

`{}`


## ▪ Inserção de Valores

Tendo criado um dicionário, é possível inserir valores executando a função `insert_key()`. Essa função é do tipo _bool_ e retornará _true_ caso a inserção seja bem sucedida e _false_ caso a inserção falhe. O único erro possível na inserção de valores refere-se a memória insuficiente.

Sintaxe:

```c
bool insert_key(No *dicionario, char *key, char *meaning);
```

Exemplo: 

```c
char keys[3][64] = {"Arroz",
                    "Árvore",
                    "Espanha"};

char meanings[3][64] = {"Comida típica.",
                        "Ser vivo.",
                        "País europeu."};
```
```python
for (int i = 0; i < 3; i++)
    insert_key(dicionario, keys[i], meanings[i]);

show_dict(dicionario);
```

Retorno:

```python
{'Arroz': 'Comida típica.', 'Árvore': 'Ser vivo.', 'Espanha': 'País europeu.'}
```

## ▪ Remoção de Valores

Também é possível deletar valores do dicionário utilizando a função `delete_key()`. Essa função é do tipo _bool_ e retornará _true_ caso a inserção seja bem sucedida e _false_ caso a inserção falhe. Os únicos erros possíveis na deleção de valores referem-se a quando o dicionário é vazio ou quando a chave informada não existe (_NULL_).

Sintaxe:

```c
bool delete_key(No *dicionario, char *key);
```

Exemplo: 

```c
delete_key(dicionario, keys[1]);

show_dict(dicionario);
```

Retorno:

```python
{'Arroz': 'Comida típica.', 'Espanha': 'País europeu.'}
```

## ▪ Remoção de Dicionário

Para remover um dicionário por completo, basta utilizar a função `delete_dict()`. Essa função é do tipo _void_ e não retornará nada.

Sintaxe:

```c
void delete_dict(No *dicionario);
```

Exemplo: 

```c
delete_dict(dicionario);
```

## ▪ Número de Chaves

Para obter o número de chaves em um dicionário, basta executar a função `num_of_keys()`. Essa função é do tipo _int_ e retornára o número de chaves dentro do dicionário.

Sintaxe:

```c
int num_of_keys(No *dicionario);
```

Exemplo: 

```c
int n = num_of_keys(dicionario);
```

## ▪ Ordenação de Dicionário

Outra função existente é a de organizar alfabeticamente as chaves de um dicionário. Para chamar essa função, basta utilizar `sort_dict()`. Essa função é do tipo _void_ e não retornará nada.

Sintaxe:

```c
void sort_dict(No *dicionario);
```

Exemplo: 

```c
show_dict(dicionario);

sort_dict(dicionario);

show_dict(dicionario);
```

Retorno: 

```python
{'Espanha': 'País europeu.', 'Arroz': 'Comida típica.'}
{'Arroz': 'Comida típica.', 'Espanha': 'País europeu.'}
```

## ▪ Pesquisa de Valores

A biblioteca também contém diferentes funções de pesquisa de conteúdos e chaves no dicionário. Essas funções são `search_meaning_byKey()`, `search_id_byKey()`, `search_meaning_byId()` e `search_key_byId()`. Tais funções realizam, respectivamente, uma busca do conteúdo de determinada chave, uma busca do id de determinada chave, uma busca do conteúdo de determinado id e, por fim, uma busca da chave de um determinado id. As funções que retornam strings, ou seja, as que procuram por chaves e conteúdos, retornarão _NULL_ caso a busca não tenha sucesso. Por outro lado, a função que busca por id retornará _void_ caso a busca não tenha sucesso.

Sintaxes:

```c
char *search_meaning_byKey(No *dicionario, char *key);
char *search_meaning_byId(No *dicionario, int id);
char *search_key_byId(No *dicionario, int id);
int search_id_byKey(No *dicionario, char *key);
```

Exemplo: 

```c
show_dict(dicionario);

char key[] = "Arroz";
char *string = malloc(sizeof(char) * 64);

string = search_meaning_byKey(dicionario, key);

if (string != NULL)
    printf("\nSignificado de '%s': '%s'\n", key, string);
```

Retorno: 

```
{'Arroz': 'Comida típica.', 'Espanha': 'País europeu.'}
Significado de 'Arroz': 'Comida típica.'
```

## ▪ Utilidades

### ▪ Alteração de Tamanho das Strings

Caso sinta necessidade, é possível alterar o tamanho das strings dos dicionários. Por padrão, o tamanho é de _64 bytes_, ou seja, 64 caracteres. Para alterar isso, vá na aba de pré-processamento no arquivo _dict.c_ e altere o macro MAX para o tamanho desejado.

Padrão:

```c
#define MAX 64
```

Alteração:

```c
#define MAX [insira_novo_tamanho]
```