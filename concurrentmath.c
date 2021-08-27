#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"concurrentmath.h"

coordinate* calcular(int xMax, int xMin, int a, int b, int c){
    coordinate* coor = (coordinate*) malloc(sizeof(coordinate)*(xMax+abs(xMin)));
    
    for(int i = xMin; i < xMax; i++){
        coor[i+xMax].x = i;
        coor[i+xMax].y = a*i*i+b*i+c;
    }

    return coor;
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

//fita de operações - maquina de turing -- matriz: opeção /- posi~çao na str

void substitui(char* str){
    // x*22*9/18*5*x
    
    int size = strlen(str);
    char* nstr =  (char*) malloc(sizeof(char)*size);
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