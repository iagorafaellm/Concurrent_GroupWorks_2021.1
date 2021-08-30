#pragma once
#ifndef CONCURRENTMATH_H

    int nthreads; //número de threads a serem criadas

    ///the coordinates where we store the values
    typedef struct{
        int x;
        int y;
    }coordinate;

    coordinate *coordsArray;

    typedef struct{
        int pos;
        char* number;
    }equation;

    //argumentos da função calcular
    typedef struct{
        int xMax;
        int xMin
        int a;
        int b;
        int c;
    }calcArg;

    void* calcular(void* arg);
    void* transform(char* eq);
    void substitui(char* str);

#endif