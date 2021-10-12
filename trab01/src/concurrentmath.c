#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include "../lib/concurrentmath.h"
#include"../lib/timer.h"
#define NTHREADS 8

int gA;
int gB;
int gC;
int gXMax;
int gXMin;
coordinate* gOutput;

void* taskCalculate(void*arg){
    

    long long int id = (long long int) arg;
    
    for(int i = (id - abs(gXMin)); i < gXMax; i+=NTHREADS){
        
        gOutput[i+gXMax].x = i;
        gOutput[i+gXMax].y = gA*(i*i)+gB*i+gC;

    }
   
    pthread_exit(NULL);
}

coordinate* concurrentyCalculate(int xMax, int xMin, int a, int b, int c){
    
    gA = a;
    gB = b;
    gC = c;
    gXMin = xMin;
    gXMax = xMax;

    gOutput = (coordinate*) malloc(sizeof(coordinate)*(gXMax+abs(gXMin)));

    if(gOutput == NULL){
        printf("ERROR... malloc");
        exit(1);
    }

    pthread_t *tid;
    tid = (pthread_t*) malloc(sizeof(pthread_t)*NTHREADS);
    if(tid == NULL){
        printf("ERROR... malloc");
        exit(1);
    }

    coordinate** result;
    result = (coordinate**) malloc(sizeof(coordinate*)*NTHREADS);

    if(result == NULL){
        printf("ERROR... malloc");
        exit(1);
    }

    for(int i = 0; i < NTHREADS; i++){
        result[i] = (coordinate*) malloc(sizeof(coordinate) * (abs(xMax) + abs(xMin)));
        
        if(result[i] == NULL){
            printf("ERROR... malloc");
            exit(1);
        }
    }    

    for(long long int i = 0; i < NTHREADS; i++){        
        if(pthread_create(tid+i, NULL, taskCalculate, (void*)i)){
            printf("ERROR... pthread_create");
            exit(2);
        }
    }
    
    for(int i = 0; i < NTHREADS; i++){
        if(pthread_join(*(tid+i), NULL)){
            printf("ERROR... pthread_join");
            exit(3);
        }
    }
    
    return gOutput;
}

coordinate* calculate(int xMax, int xMin, int a, int b, int c){
    coordinate* coor = (coordinate*) malloc(sizeof(coordinate)*(xMax+abs(xMin)));
    
    for(int i = xMin; i < xMax; i++){
        coor[i+xMax].x = i;
        coor[i+xMax].y = a*(i*i)+b*i+c;
    }

    return coor;
}


//fita de operações - maquina de turing -- matriz: opeção /- posi~çao na str

// void substitui(char* str){
//     // x*22*9/18*5*x
    
//     int size = strlen(str);
//     char* nstr =  (char*) malloc(sizeof(char)*size);
//     strcpy(nstr, str);
//     char* operations = (char*) malloc(sizeof(char)*size);
//     equation numberpr;
//     equation numberpo;

//     //x*x*x+77-8*x+5/2
//     for(int i = 0; i < size;i++){
//         if(nstr[i] == '-' || nstr[i] == '+' || nstr[i] == '*' || nstr[i] == '/'){
//             operations[i] = str[i];
//             int count = 1;
//             numberpr.number = (char*) malloc(sizeof(char)*10);
//             numberpo.number = (char*) malloc(sizeof(char)*10);

//             while(i-count >= 0 && i+count < size){

//                 if(nstr[i-1] == 'x' ){
//                     numberpr.number[0] = 'x';
//                     numberpr.pos = i;
//                 }
//                 else{
//                     if(str[i-count] > '0' && str[i-count] < '9'){
//                         numberpr.number[count-1] = str[i-count];
//                         numberpr.pos = i;
//                     }
//                 }
//                 if(nstr[i+1] == 'x'){
//                     numberpo.number[0] = 'x';
//                     numberpo.pos = i;
//                 }
//                 else{
//                     if(str[i+count] > '0' && str[i+count] < '9'){
//                         numberpo.number[count-1] = str[i+count];
//                         numberpo.pos = i;
//                     }
//                 }
                
//                 count++;
//             }

//             if(strlen(numberpr.number) > 0){
//                 printf("pre: %s\n", numberpr.number);
//                 printf("%c\n", operations[numberpr.pos]);
//             }
            
//             if(strlen(numberpo.number) > 0){
//                 printf("pos: %s\n\n", numberpo.number);
//                 //printf("-- %c\n", operations[numberpo.pos]);
//             }
//         }
//     }
// }


void maquina(char* str, int min, int max){
    
    char* pilha = (char*) malloc(sizeof(char)* strlen(str));

    for(int i =min; i < max; i++){
        int count = 0;
        while(count < strlen(str)){
            
            switch (str[count])
            {
            case '*':
                if(pilha[sizeof(pilha)-1] == 'x'){
                    pilha[sizeof(pilha)-1] = pilha[sizeof(pilha)-1] * str[count+1];
                }
                
                break;
            
            case '/':
                
                break;
            
            case '+':
                
                break;

            case '-':
                
                break;
                
            default:
                pilha[sizeof(pilha)] = str[count];
            }

            count ++;
        }
    }
}