#include "dict.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char keys[5][64] = {"Arroz",
                        "Árvore",
                        "Espanha",
                        "America do Sul",
                        "Oceano"};

    char meanings[5][64] = {"Comida típica.",
                            "Ser vivo.",
                            "País europeu.",
                            "Continente",
                            "Mares que separam continentes."};

    No *dicionario = create_dict();

    for (int i = 0; i < 5; i++)
        insert_key(dicionario, keys[i], meanings[i]);

    show_dict(dicionario);

    delete_key(dicionario, keys[4]);
    delete_key(dicionario, keys[1]);

    puts("");
    show_dict(dicionario);

    sort_dict(dicionario);
    puts("");
    show_dict(dicionario);

    return 0;
}