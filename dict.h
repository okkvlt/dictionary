#ifndef DICT_H
#define DICT_H
#include <stdbool.h>

typedef struct dict Dict;

typedef struct no No;

/**
 * Cria um dicionário vazio!
 * @retval No* — Endereço do nó descritor.
 */
No *create_dict();

/**
 * Insere um valor no dicionário.
 * @param No* Endereço do nó descritor.
 * @param char* String com a chave.
 * @param char* String com o valor da chave.
 * @retval true — Chave inserida com sucesso!
 * @retval false — Falha ao inserir chave!
 */
bool insert_key(No *, char *, char *);

/**
 * Deleta um valor do dicionário.
 * @param No* Endereço do nó descritor.
 * @param char* String com a chave.
 * @retval true — Chave deletada com sucesso!
 * @retval false — Falha ao deletar chave!
 */
bool delete_key(No *, char *);

/**
 * Deleta o dicionário.
 * @param No* Endereço do nó descritor.
 * @retval true — Dicionário deletado com sucesso!
 * @retval false — Falha ao deletar dicionário!
 */
bool delete_dict(No *);

/**
 * Printa o dicionário.
 * @param No* Endereço do nó descritor.
 * @return void.
 */
void show_dict(No *);

/**
 * Mostra o número de keys no dicionário.
 * @param No* Endereço do nó descritor.
 * @retval int — Número de chaves.
 */
int num_of_keys(No *);

/**
 * Organiza o dicionário em ordem alfabética.
 * @param No* Endereço do nó descritor.
 * @return void.
 */
void sort_dict(No *);

#endif