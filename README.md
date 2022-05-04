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

## ▪ Inserção de Valores

Tendo criado um dicionário, é possível inserir valores executando a função `insert_key()`. Essa função é do tipo _bool_ e retornará _true_ caso a inserção seja bem sucedida e _false_ caso a inserção falhe. A único erro possível na inserção de valores refere-se a memória insuficiente.

Sintaxe:

```c
insert_key(No *no, char *key, char *meaning);
```

Exemplo: 

```c
char key[] = "Árvore";
char meaning[] = "Ser vivo.";

if (!insert_key(dicionario, key, meaning)
  puts("Erro de memória!");
```