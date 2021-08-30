#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include "../lib/concurrentmath.h"

void* calcular(void* arg){
    calcArg args = *(calcArg *) arg;
    coordinate* coor = (coordinate*) malloc(sizeof(coordinate)*(args.xMax+abs(args.xMin)));
    
    for(int i = args.xMin; i < args.xMax; i++){
        coor[i+args.xMax].x = i;
        coor[i+args.xMax].y = (args.a*i*i)+(args.b*i)+args.c;
    }

    pthread_exit((void *) coor);
}

//cria os identificadores da threads
pthread_t* createTid() {
pthread_t* tid = (pthread_t *) malloc(sizeof(pthread_t) * nthreads);
  if (tid == NULL) {
    printf("ERRO--createTid");
    exit(-1);
  }

  return tid;
}

//cria as threads
void createThread(pthread_t tid[]) {
    calcArg args[nthreads];
    for(int i = 0; i < nthreads; i++) {
        args[i].xMax = width/2;
        args[i].xMin = (-width/2) + i;
        args[i].a = -1;
        args[i].b = 0;
        args[i].c = 0;


        if (pthread_create(&tid[i], NULL, calcular, (void *) &args[i])) {
            printf("Erro na pthread_create()\n");
            exit(-2);
        }
    }
}

//espera as threads terminarem
void joinThread(pthread_t tid[]) {
    for(int i = 0; i < nthreads; i++) {
        void* argCoor; //variável que usamos para armazenar o retorno da função calcular

        if (pthread_join(tid[i], &argCoor)) {
            printf("Erro na pthread_join()\n");
            exit(-3);
        }

        coordinate* coord = (coordinate *) argCoord; //váriavel que armazena os pontos a serem plotados
    }

    // for(int i = 0; i < nthreads; i += nthreads){
        
        
    // }     
}

void* transform(char* eq){
    char* token;
    char* str;
    char deli[3] = "x";
    token = strtok(eq,deli);

    while (token!=NULL)
    {
        str = (char*) malloc(sizeof(char)*strlen(token));
        // if(strpbrk(token, 'x'))
            // substitui(token);
        printf("%s\n",token);
        token = strtok(NULL, deli);        
    }
}

void substitui(char* str){
    // x*22*9/18*5*x
    
    int size = strlen(str);
    char* nstr = (char*) malloc(sizeof(char)*size);
    strcpy(nstr, str);
    char* operations = (char*) malloc(sizeof(char)*size);
    equation numberpr;
    equation numberpo;

    //x*x*x+77-8*x+5/2
    for(int i = 0; i < size;i++){
        if(nstr[i] == '-' || nstr[i] == '+' || nstr[i] == '*' || nstr[i] == '/'){
            operations[i] = str[i];
            int count = 1;
            numberpr.number = (char*) malloc(sizeof(char)*10);
            numberpo.number = (char*) malloc(sizeof(char)*10);

            while(i-count >= 0 && i+count < size){

                if(nstr[i-1] == 'x' ){
                    numberpr.number[0] = 'x';
                    numberpr.pos = i;
                }
                else{
                    if(str[i-count] > '0' && str[i-count] < '9'){
                        numberpr.number[count-1] = str[i-count];
                        numberpr.pos = i;
                    }
                }
                if(nstr[i+1] == 'x'){
                    numberpo.number[0] = 'x';
                    numberpo.pos = i;
                }
                else{
                    if(str[i+count] > '0' && str[i+count] < '9'){
                        numberpo.number[count-1] = str[i+count];
                        numberpo.pos = i;
                    }
                }
        
                count++;
            }

            if(strlen(numberpr.number) > 0){
                printf("pre: %s\n", numberpr.number);
                printf("%c\n", operations[numberpr.pos]);
            }
            
            if(strlen(numberpo.number) > 0){
                printf("pos: %s\n\n", numberpo.number);
                //printf("-- %c\n", operations[numberpo.pos]);
            }
        }
    }
}