#pragma once
#ifndef CONCURRENTMATH_H

    ///the coordinates where we store the values
    typedef struct{
        int x;
        int y;
    }coordinate;

    coordinate* calculate(int xMax, int xMin, int a, int b, int c);      
    coordinate* concurrentyCalculate(int xMax, int xMin, int a, int b, int c);

#endif