#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "alocacao.h"
#include "prompt.h"

#define TRUE 1
#define COMMAND 20
#define PARAMETERS 20

int main(void)
{
    char *binary_path = alocar_char(100);
    char *command = alocar_char(COMMAND);
    char **parameters = alocar_char_alt(PARAMETERS);
    int status;

    while(TRUE) {
        type_prompt();
        read_command(command, parameters);
        
        if(strcmp(command, "exit") == 0)
            break;
   
        if(fork() != 0) {
            waitpid(-1, &status, 0);
        } else {
            strcpy(binary_path, "/bin/");
            strcat(binary_path, command);
            execve(binary_path, parameters, NULL);
        };

    };

    liberar_char(binary_path);
    liberar_char(command);
    liberar_char_alt(parameters);

	return 0;
}

