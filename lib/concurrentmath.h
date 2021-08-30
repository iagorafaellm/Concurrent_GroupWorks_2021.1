#pragma once
#ifndef CONCURRENTMATH_H

    //variáveis globais
    int nthreads; //número de threads a serem criadas
    coordinate coordsArray[];

    ///the coordinates where we store the values
    typedef struct{
        int x;
        int y;
    }coordinate;

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