#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct {
    int burst_time;
    int espera;
    char concluido;
} Processo;

int main(void) {
    Processo *processo = NULL;
    int quantum;
    int tempo = 0;
    int concluidos = 0;
    int i;

    processo = (Processo *) malloc(N * sizeof(Processo));

    if(processo == NULL) {
        puts("Erro ao alocar memória.\n");
        exit(1);
    }

    printf("Informe o quantum: ");
    scanf("%d", &quantum);

    printf("Informando o tempo de burst: \n");
    for(i = 0; i < N; i++) {
        processo[i].espera = 0;
        processo[i].concluido = 'n';
        printf("Tempo de burst do processo %d: ", i + 1);
        scanf("%d", &processo[i].burst_time);
    }
    
    while(1) {
        puts("=======================================\n");

        for(i = 0; i < N; i++) {

            if(processo[i].concluido == 's') // o processo já foi concluído
                continue;

            printf("Processo %d: burst time: %d\n", i+1, processo[i].burst_time);

            processo[i].espera = tempo - processo[i].espera;

            if(processo[i].burst_time > quantum) {
                processo[i].burst_time -= quantum; // reduz o tempo de processamento
            } else {
                processo[i].burst_time = 0;
                processo[i].concluido = 's';
                printf("O processo %d foi concluído.\n", i + 1);
                concluidos += 1;
            }

            tempo += quantum + 1; // 1 unidade de tempo por mudança de contexto
        }
    
        if (concluidos == N)
            break;
    }

    // média de espera
    int soma;
    for(i = 0; i < N; i++)
        soma += processo[i].espera;

    printf("Tempo médio de espera: %.2f\n", (float) soma / N);

    // média de retorno
    printf("Tempo médio de retorno: %.2f\n", (float) tempo / N);

    free(processo);

    return 0;
}
