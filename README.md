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

```python
show_dict(No *no);
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
insert_key(No *no, char *key, char *meaning);
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

## ▪ Deleção de Valores

Também é possível deletar valores do dicionário utilizando a função `delete_key()`. Essa função é do tipo _bool_ e retornará _true_ caso a inserção seja bem sucedida e _false_ caso a inserção falhe. O único erro possível na deleção de valores refere-se a quando o dicionário é vazio.

Sintaxe:

```c
delete_key(No *no, char *key);
```

Exemplo: 

```c
delete_key(dicionario, keys[1]);
```

Retorno:

```python
{'Arroz': 'Comida típica.', 'Espanha': 'País europeu.'}
```