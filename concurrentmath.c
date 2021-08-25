#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"concurrentmath.h"

coordinate* calcular(int xMax, int xMin, int a, int b, int c){
    coordinate* coor = (coordinate*) malloc(sizeof(coordinate)*(xMax+abs(xMin)));
    
    for(int i = xMin; i < xMax; i++){
        coor[i+xMax].x = i;
        coor[i+xMax].y = a*i*i+b*i+c;
    }
    return coor;
}