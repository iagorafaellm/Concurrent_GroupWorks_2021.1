#pragma once
#ifndef CONCURRENTMATH_H

    ///the coordinates where we store the values
    typedef struct{
        int x;
        int y;
    }coordinate;

    typedef struct{
        int pos;
        char* number;
    }equation;


    coordinate* calcular(int xMax, int xMin, int a, int b, int c);
    void* transform(char* eq);
    void substitui(char* str);


#endif