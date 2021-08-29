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

    typedef struct{
        int xMax, xMin, a, b, c;
    }calcArg;

    void* calcular(void* arg);
    void* transform(char* eq);
    void substitui(char* str);

#endif