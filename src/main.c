#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include <pthread.h>
#include"../lib/bmp.h"
#include"../lib/concurrentmath.h"
#include"../lib/timer.h"

int main(int argc, char* argv[]){

    double begin;
    double end;
    
    int range = 1000;

    int a,b,c;

    if(argc > 3){        
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
    }
    else{
        printf("./main <a> <b> <c>\n");
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

    
    for(int i =0; i < range; i++){
        if(calculateConc[i].x != caclculateSeq[i].x || calculateConc[i].y != caclculateSeq[i].y){
            printf("seq: [%d, %d]\n", caclculateSeq[i].x, caclculateSeq[i].y);
            printf("conq: [%d, %d]\n", calculateConc[i].x, calculateConc[i].y);
        }
    }
    
    printf("Generating the BITMAP: \n");

    GET_TIME(begin);
    generateBitmapImage(caclculateSeq, range, range, imageFileName);
    GET_TIME(end);
    printf("    Sequential: %lf\n", end-begin);

     GET_TIME(begin);
    concurrentyGenerateBitmapImage(caclculateSeq, range, range);
    GET_TIME(end);
    printf("    Concurrent: %lf\n", end-begin);

    printf("Image generated!\n");

}