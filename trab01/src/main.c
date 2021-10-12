#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include <pthread.h>
#include"../lib/bmp.h"
#include"../lib/concurrentmath.h"
#include"../lib/timer.h"
#define MAXDIGIT 100

coordinate* expressao(int range, char* exp){
    char* str = exp;

    // if(argc > 1){   
    //     str=argv[1];        
    // }
    // else
    //     str = "5*2*2*5*2/2/10";    


    printf("%s\n", str);
    //int range = 10;
    char** pilha;
    coordinate* result = (coordinate*) malloc(sizeof(coordinate)*range+2+1);    
    //int cont, in;

    for(int i = -range/2; i < range/2; i++){

        pilha = (char**) malloc(sizeof(char*)* strlen(str)+1);        
        for(int k = 0; k < strlen(str)+1; k++){
            pilha[k] = (char*) malloc(sizeof(char)*MAXDIGIT);
        }

        int cont = 0, in = 0;
        
        while(cont <= strlen(str)){
            //printf("i: %d str:%c\n", i, str[cont]);
            if((str[cont] == '*' || str[cont] == '/' || str[cont] == '+' || str[cont] == '-' || str[cont] == '\0') && in >= 3){
                
                if(!strcmp(pilha[in-2], "*")){
                    printf("%s * %s\n", pilha[in-1], pilha[in-3]);
                    sprintf(pilha[in-3], "%d", atoi(pilha[in-1])*atoi(pilha[in-3]));
                    in-=2;
                }
                else{                   
                    if(!strcmp(pilha[in-2], "/")){                        
                        sprintf(pilha[in-3], "%d", atoi(pilha[in-3])/atoi(pilha[in-1]));
                        in-=2;
                    }
                }
                if(str[cont] != '\0'){
                    sprintf(pilha[in], "%c", str[cont]);
                }                
               
            }
            else{
                if(str[cont] > '0' && str[cont] < '9'){
                    
                    sprintf(pilha[in], "%d", atoi(str+cont));
                    //printf("coloquei: %s\n", pilha[in]);
                   
                }
                else{
                    
                    if(str[cont] == 'x')
                        sprintf(pilha[in], "%d", i);
                    else
                        sprintf(pilha[in], "%c", str[cont]);
                }
                
            }
            //printf("aaaaa\n");
            
            //printf("sssss\n");
            if(cont != strlen(str) && str[cont] != 'x')
                cont += strlen(pilha[in]);
            else
                cont++;            
            in++;
           
        }
        cont = 1;
        //printf("--%d , %d, %d\n", i, in, cont);
        while(cont < in-1){
            if(!strcmp(pilha[1], "+")){
                printf("%s + %s\n", pilha[0], pilha[2]);
                sprintf(pilha[0], "%d", atoi(pilha[0]) + atoi(pilha[2]));            
            }
            else{
                if(!strcmp(pilha[1], "-")){
                    printf("%s - %s\n", pilha[0], pilha[2]);
                    sprintf(pilha[0], "%d", atoi(pilha[0]) - atoi(pilha[2]));
                }
            }
            for(int j = 1; j < in-cont+1; j++){
                //printf("j: %d\n", j);
                if(j+2 < in){
                    pilha[j] = pilha[j+2];
                    //printf("pilha: %s\n", pilha[j]);
                }
                //printf("aaaa\n");
            }            
            cont+=2;
        }
        result[i+range/2].x=i;
        result[i+range/2].y=atoi(pilha[0]);        
    }
    
    // cont = 1;
        
    // while(cont < in-1){
    //     if(!strcmp(pilha[1], "+")){
    //         printf("%s + %s\n", pilha[0], pilha[2]);
    //         sprintf(pilha[0], "%d", atoi(pilha[0]) + atoi(pilha[2]));            
    //     }
    //     else{
    //         if(!strcmp(pilha[1], "-")){
    //             printf("%s - %s\n", pilha[0], pilha[2]);
    //             sprintf(pilha[0], "%d", atoi(pilha[0]) - atoi(pilha[2]));
    //         }
    //     }
    //     for(int i = 1; i < in-cont; i++){
    //         pilha[i] = pilha[i+1];
    //     }
    //     cont++;
    // }
    // for(int i=0;i <= range;i++){
    //     printf("[%d,%d]\n", result[i].x,result[i].y);
    // }

    return result;
    free(pilha);
    free(result);
}

int main(int argc, char* argv[]){

    double begin;
    double end;
    
    int range = 1000;

    int a = 1,b = 1,c = 1;
    char* str;
    if(argc > 1){        
        str = argv[1];
    }
    else{
        printf("./main <expressao> \n");
        return -1;
    }
    
    char* imageFileName;
    imageFileName = (char*) malloc(sizeof(int)*2 + sizeof(char)*5);
    sprintf(imageFileName,"%dx%d.bmp",range,range);
    
    printf("Computing the function: \n");

    GET_TIME(begin);
    coordinate* caclculateSeq = calculate(range/2,-range/2,a,b,c);
    GET_TIME(end);
    printf("    Sequential: %lf\n", end-begin);

    GET_TIME(begin);
    coordinate* calculateConc = concurrentyCalculate(range/2,-range/2,a,b,c);
    GET_TIME(end);
    printf("    Concurrent: %lf\n", end-begin);
    coordinate* pilha = expressao(range,str);
    
    for(int i =0; i < range; i++){
        if(calculateConc[i].x != caclculateSeq[i].x || calculateConc[i].y != caclculateSeq[i].y){
            printf("seq: [%d, %d]\n", caclculateSeq[i].x, caclculateSeq[i].y);
            printf("conq: [%d, %d]\n", calculateConc[i].x, calculateConc[i].y);
        }
    }
    
    printf("Generating the BITMAP: \n");

    GET_TIME(begin);
    generateBitmapImage(pilha, range, range, imageFileName);
    GET_TIME(end);
    printf("    Sequential: %lf\n", end-begin);

    // GET_TIME(begin);
    // concurrentyGenerateBitmapImage(caclculateSeq, range, range);
    // GET_TIME(end);
    // printf("    Concurrent: %lf\n", end-begin);

    printf("Image generated!\n");

}