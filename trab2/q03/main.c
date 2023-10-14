#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define LEITORES 10 
#define ESCRITORES 5

// protótipos de funções
void *leitor();
void *escritor();
void escrevendo();
void lendo();

// mutexes
pthread_mutex_t escrever;
pthread_mutex_t ler;

//threads
pthread_t leitores[LEITORES];
pthread_t escritores[ESCRITORES];

int qtd_leitores = 0;


int main(void) {
    // inicialização dos mutexs
	pthread_mutex_init(&escrever, NULL);
    pthread_mutex_init(&ler, NULL);

    int i;

    // criação das threads
    for(i = 0; i < LEITORES; i++)
        pthread_create(&leitores[i], NULL, leitor, NULL);

    for(i = 0; i < ESCRITORES; i++)
        pthread_create(&escritores[i], NULL, escritor, NULL);

    // espera pelo término das threads
    for(i = 0; i < LEITORES; i++)
        pthread_join(leitores[i], NULL);
    
    for(i = 0; i < ESCRITORES; i++)
        pthread_join(escritores[i], NULL);

	return 0;
}

void *leitor() {
	while(1) {    
		pthread_mutex_lock(&escrever);
        
        qtd_leitores++;

		if(qtd_leitores == 1) 
			pthread_mutex_lock(&ler);
		
		pthread_mutex_unlock(&escrever);

		lendo();
	
        pthread_mutex_lock(&escrever);
		
        qtd_leitores--;

        if(qtd_leitores == 0)
            pthread_mutex_unlock(&ler);

        pthread_mutex_unlock(&escrever);
	}
}

void *escritor() {
	while(1) {
		pthread_mutex_lock(&escrever);
		
		escrevendo();
		
		pthread_mutex_unlock(&escrever);
	}
}

void escrevendo() {
    printf("Escrevendo...\n");
    
    srand(time(NULL));
    int espera = rand() % 10;

    sleep(espera);
}

void lendo() {
    printf("Lendo...\n");
    
    srand(time(NULL));
    int espera = rand() % 5;

    sleep(espera);
};
