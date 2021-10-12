#pragma once
#ifndef BMP_H
    
    #define BYTES_PER_PIXEL 3 /// red, green, & blue
    #define FILE_HEADER_SIZE 14 
    #define INFO_HEADER_SIZE 40

    typedef struct{
        int x;
        int y;
    }point;

    //generates concurrently the image
    void concurrentyGenerateBitmapImage (point* points,int height, int width);
    //generate the image
    void generateBitmapImage(point* coor, int height, int width, char* imageFileName);

#endif