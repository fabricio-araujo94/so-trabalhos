#include <stdio.h>
#include <stdlib.h>
#include "alocacao.h"

char *alocar_char(int qtd) {
    char *array = (char *) malloc(qtd * sizeof(char));

    if(array == NULL) {
        puts("Não foi possível alocar na memória.");
        exit(1);
    }

    return array;
}

void liberar_char(char *p) {
    free(p);
}

char **alocar_char_alt(int qtd) {
    char **array = (char **) malloc(qtd * sizeof(char));

    if(array == NULL) {
        puts("Não foi possível alocar na memória.");
        exit(1);
    }

    return array;
}

void liberar_char_alt(char **p) {
    free(p);
}

