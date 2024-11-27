#include <stdio.h>
#include <string.h>

#include "alocacao.h"
#include "prompt.h"

#define TAM 1024

void type_prompt() {
    printf("> ");
}

void read_command(char *command, char **parameters) {
    char *texto = alocar_char(TAM);
    char **array = alocar_char_alt(21);
    char *palavras;
    int i = 0, j = 0;

    scanf("%[^\n]%*c", texto);

    palavras = (char *) strtok(texto, " ");

    i = 0;
    while(palavras != NULL) {
        array[i++] = strdup(palavras);
        palavras = strtok(NULL, " ");
    }

    strcpy(command, array[0]);

    for(j = 0; j < i; j++) {
        parameters[j] = array[j];
    }
    parameters[i] = NULL;

    liberar_char(texto);
    liberar_char_alt(array);
}
