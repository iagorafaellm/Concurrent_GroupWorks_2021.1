#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include "../lib/concurrentmath.h"

void* calcular(void* arg){
    calcArg args = *(calcArg *) arg;
    coordinate* coor = (coordinate*) malloc(sizeof(coordinate)*(args.xMax+abs(args.xMin)));

    //printf("%d\n", args.xMin);
        
    
    for(int i = args.xMin; i < args.xMax; i += nthreads){
        coor[i+args.xMax].x = i;
        coor[i+args.xMax].y = (args.a*i*i)+(args.b*i)+args.c;

        
        //printf("%d %d\n", coor[i+args.xMax].x, coor[i+args.xMax].y);

        coordsArray[i+args.xMax] = *coor;
    }
    pthread_exit(NULL);
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
void createThread(pthread_t tid[], calcArg argsBase) {
    calcArg args[nthreads];
    for(int i = 0; i < nthreads; i++) {
        args[i].xMax = argsBase.xMax;
        args[i].xMin = argsBase.xMin + i;
        args[i].a = argsBase.a;
        args[i].b = argsBase.b;
        args[i].c = argsBase.c;

        printf("%d\n", args[i].xMin);

        

        if (pthread_create(&tid[i], NULL, calcular, (void *) &args[i])) {
            printf("Erro na pthread_create()\n");
            exit(-2);
        }
    }
}

//espera as threads terminarem
void joinThread(pthread_t tid[]) {
    for(int i = 0; i < nthreads; i++) {
        //variável que usamos para armazenar o retorno da função calcular

        if (pthread_join(tid[i], NULL)) {
            printf("Erro na pthread_join()\n");
            exit(-3);
        }

        
    }
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