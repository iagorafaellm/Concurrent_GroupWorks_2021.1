/* Disciplina: Computação Concorrente - 2021.1 */
/* Prof.: Silvana Rossetto */
/* Integrantes: Iago Rafael Lucas Martins, Lucas Moreno Silva, Pedro Ancelmo de Aquino Vieira Amaral */
/* Módulo 2 - Segundo Trabalho de Implementação */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define BUFFERSIZE 10

FILE* file;
char* fileName = "in.txt";

//variáveis globais
int N, C;
int** buffer;
FILE* fileOutput;

int out = 0;
int quantDig;
int cont = 0;


sem_t slotCheio, slotVazio; //condição
sem_t mutexCons; //exclusão mútua

//função para abrir o arquivo
void openFile(){
    
    char* outputName = "output.txt";
    fileOutput = fopen(outputName,"w");
    file = fopen(fileName, "r");
    if(file == NULL || fileOutput == NULL){
        printf("ERROR... fopen");
        exit(1);
    }
}

void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

void bubbleSort(int *v, int n){    
    if (n < 1)return;

    for (int i = 0; i < n-1; i++)
        if (v[i] > v[i + 1])
            swap(&v[i], &v[i + 1]);
    bubbleSort(v, n - 1);
}

void retira(int id){
    static int out = 0;

    //aguarda slot cheio
    sem_wait(&slotCheio);
    
    //exclusão mútua entre consumidores
    sem_wait(&mutexCons);
    //ordena o vetor antes de printar
    bubbleSort(buffer[out], N);
    
    for(int i = 0; i < N; i++){        
        fprintf(fileOutput, "%d ", buffer[out][i]);
    }
    
    out = (out + 1) % BUFFERSIZE;

    fprintf(fileOutput,"\n");
    
    //sinaliza 
    sem_post(&mutexCons);
    
    //sinaliza um slot vazio    
    sem_post(&slotVazio);
    
}

//função consumidora
void *consumidora(void* args){
    
    int id = (long long int)args;
    static int count = 0;
    while(1){
        sem_wait(&mutexCons);
        
        if(count >= quantDig/N){            
            exit(1);
        }
        sem_post(&mutexCons);
        retira(id);
        
        sem_wait(&mutexCons);
        count++;
        sem_post(&mutexCons);
    }
    pthread_exit(NULL);
}

int insere(){
    
    sem_wait(&slotVazio);
    
    for(int i = 0; i < N; i++){
        int temp;
        if(fscanf(file,"%d", &temp) == EOF){            
            return 1;
        }

        buffer[cont][i] = temp;
    }

    cont = (cont+1)%BUFFERSIZE;
    
    sem_post(&slotCheio);
    return 0;
}

void* produtora(void* args){
    while(1){
        if(insere()){            
            break;
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    
    if(argc > 2){
        N = atoi(argv[1]);
        C = atoi(argv[2]);
    }
    else{
        printf("Escreva nesse modelo: %s <número de linhas> <número de threads consumidoras>\n", argv[0]);
        return 1;
    }
    openFile();
    
    fscanf(file, "%d", &quantDig);
    printf("%d\n", quantDig);
    
    buffer = (int**) malloc(sizeof(int*) * BUFFERSIZE);
    for(int i = 0; i < BUFFERSIZE; i++){
        buffer[i] = (int*) malloc(sizeof(int*)*N);
    }

    sem_init(&mutexCons, 0, 1);
    sem_init(&slotCheio, 0, 0);
    sem_init(&slotVazio, 0, 10);

    pthread_t* tidCons = (pthread_t *) malloc(sizeof(pthread_t) * C);
    if (tidCons == NULL) {
        printf("ERROR... malloc");
        return 1;
    }

    pthread_t tidProd;    

    for (long long i = 0; i < C; i++) {
        if (pthread_create(tidCons+i, NULL, consumidora, (void *)i)) {
            printf("ERROR...createThreads\n");
            return 2;
        }
    }

    if (pthread_create(&tidProd, NULL, produtora, (void *)0)) {
        printf("ERROR...createThreads\n");
        return 2;
    }

    if(pthread_join(tidProd, NULL)) {
        printf("ERROR...pthread_join");
        return 3;
    }

    for (int i = 0; i < C; i++) {
        if(pthread_join(tidCons[i], NULL)) {
            printf("ERROR...pthread_join");
            return 3;
        }
    }

    sem_destroy(&slotCheio);
    sem_destroy(&slotVazio);
    sem_destroy(&mutexCons);

    return 0;
}