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

char ope[5] = "-+*/";

void substitui(char* str){
    // x*22*9/18*5*x
    int num;
    for(int i = 0; i < strlen(str);i++){

        if(str[i] > 0 && str[i] < 9){
            num = atoi(str[i]);
        }
    }
    
    // for(int i = 0; i < max, i++){
        
    // }
}