#include "dict.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 64

// structs

struct dict
{
    int id;
    char key[MAX];
    char meaning[MAX];
    struct dict *prox;
};

struct no
{
    Dict *head;
    int qty;
};

// aux functions

Dict *createNFill(char *key, char *meaning)
{
    Dict *novo = malloc(sizeof(Dict));
    if (novo != NULL)
    {
        strcpy(novo->key, key);
        strcpy(novo->meaning, meaning);
        novo->prox = NULL;
    }
    return novo;
}

bool checkSort(char *x, char *y)
{
    int max = strlen(x);

    for (int i = 0; i < max; i++)
    {
        if ((int)x[i] > (int)y[i])
            return true;
        if ((int)x[i] < (int)y[i])
            return false;
    }
    return false;
}

void swap(Dict *aux, Dict *temp)
{
    char utill_key[MAX], utill_meaning[MAX];
    Dict *utill_prox;

    strcpy(utill_key, aux->key);
    strcpy(aux->key, temp->key);
    strcpy(temp->key, utill_key);

    strcpy(utill_meaning, aux->meaning);
    strcpy(aux->meaning, temp->meaning);
    strcpy(temp->meaning, utill_meaning);
}

// implementions functions

No *create_dict()
{
    No *novo = malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->head = NULL;
        novo->qty = 0;
    }
    return novo;
}

Dict *search_end_pre_key(No *no, char *key)
{
    Dict *aux = no->head;

    if (aux == NULL)
        return NULL;

    while (aux != NULL)
    {
        if (aux->prox != NULL && strcmp(aux->prox->key, key) == 0)
            return aux;
        aux = aux->prox;
    }

    return NULL;
}

bool insert_key(No *no, char *key, char *meaning)
{
    if (search_end_pre_key(no, key) != NULL)
        return false;

    if (no->head != NULL && strcmp(no->head->key, key) == 0)
        return false;

    Dict *novo = createNFill(key, meaning);
    if (novo == NULL)
        return false;

    if (no->head == NULL)
    {
        no->head = novo;
        novo->id = 0;
    }
    else
    {
        Dict *aux = no->head;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        novo->id = aux->id + 1;
    }

    no->qty++;

    return true;
}

bool delete_key(No *no, char *key)
{
    if (no->head == NULL)
        return false;

    Dict *aux = no->head, *end;

    if (strcmp(aux->key, key) == 0)
    {
        no->head = aux->prox;
        end = aux;
    }
    else
    {
        aux = search_end_pre_key(no, key);
        if (aux == NULL)
            return false;
        end = aux->prox;
        aux->prox = aux->prox->prox;
    }

    free(end);
    no->qty--;

    return true;
}

char *search_meaning_byKey(No *no, char *key)
{
    Dict *aux = search_end_pre_key(no, key);

    if (aux != NULL)
        return aux->prox->meaning;
    return NULL;
}

int search_id_byKey(No *no, char *key)
{
    Dict *aux = search_end_pre_key(no, key);

    if (aux != NULL)
        return aux->prox->id;
}

Dict *search_byId(No *no, int id)
{
    Dict *aux = no->head;

    while (aux != NULL)
    {
        if (aux->id == id)
            return aux;
        aux = aux->prox;
    }

    return NULL;
}

char *search_meaning_byId(No *no, int id)
{
    Dict *aux = search_byId(no, id);

    if (aux != NULL)
        return aux->meaning;
    return NULL;
}

char *search_key_byId(No *no, int id)
{
    Dict *aux = search_byId(no, id);

    if (aux != NULL)
        return aux->key;
    return NULL;
}

void delete_dict(No *no)
{
    Dict *aux = no->head;
    while (aux != NULL)
    {
        free(aux);
        aux = aux->prox;
    }
    free(no);
}

void show_dict(No *no)
{
    Dict *aux = no->head;

    putchar('{');

    while (aux != NULL)
    {
        if (aux->prox != NULL)
            printf("\'%s\': \'%s\', ", aux->key, aux->meaning, aux->id);
        else
            printf("\'%s\': \'%s\'", aux->key, aux->meaning);
        aux = aux->prox;
    }

    putchar('}');
}

int num_of_keys(No *no)
{
    return no->qty;
}

void sort_dict(No *no)
{
    Dict *aux = no->head, *temp;

    while (aux != NULL)
    {
        temp = aux->prox;
        while (temp != NULL)
        {
            if (checkSort(aux->key, temp->key))
                swap(aux, temp);
            temp = temp->prox;
        }

        aux = aux->prox;
    }
}