#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include"../lib/bmp.h"
#include"../lib/concurrentmath.h"

int main(int argc, char* argv[]){

    int height = 500;
    int width  = 500;
    int range = 500;
    if(argc > 1){
        
        range = atoi(argv[1]);
    }
    //coordinate* c = calcular(250,-250,1,0,0);
    //printf("%d--%d\n",c[0].x ,c[0].y);
    
    // unsigned char image[height][width][BYTES_PER_PIXEL];
    char* imageFileName;
    imageFileName = (char*) malloc(sizeof(int)*2 + sizeof(char)*5);
    sprintf(imageFileName,"%dx%d.bmp",range,range);

    // int i, j;
    // int nj,ni;
    // int g;
    // //paint the canvas and the axis
    // for(i = 0;i<height;i++){
    //     for(j = 0; j< width;j++){
    //         if(j == width/2 || i == height/2){
    //             image[i][j][2] = 119; ///red
    //             image[i][j][1] = 136; ///blue
    //             image[i][j][0] = 153; ///green
    //         }
    //         else{
    //             image[i][j][2] = 255; ///red
    //             image[i][j][1] = 255; ///blue
    //             image[i][j][0] = 255; ///green
    //         }
    //     }
    // }

    // for (i = -height/2; i < height/2; i++) {
    //     for (j = -width/2; j < (width/2); j++) {
    //         //compare the equation
    //         if(i==j*j+20*j+20){
    //             g = j;
    //             if(j < 0){
    //                 nj = (width/2)-abs(j);
    //                 if(i<0){
    //                     ni = (height/2)-abs(i);                        
    //                     image[ni][nj][2] = 255; ///red
    //                     image[ni][nj][1] = 0; ///green
    //                     image[ni][nj][0] = 0; ///blue
    //                 }                    
    //                 else{
    //                     ni = i+(height/2);
    //                     image[ni][nj][2] = 255; ///red
    //                     image[ni][nj][1] = 0; ///green
    //                     image[ni][nj][0] = 0; ///blue
    //                 }
    //             }
    //             else{
    //                 nj = j+width/2;
    //                 if(i<0){
    //                     ni = (height/2)-abs(i);
    //                     image[ni][nj][2] = 255; ///red
    //                     image[ni][nj][1] = 0; ///green
    //                     image[ni][nj][0] = 0; ///blue
    //                 }
    //                 else{
    //                     ni = i+(height/2);
    //                     image[ni][nj][2] = 255; ///red
    //                     image[ni][nj][1] = 0; ///green
    //                     image[ni][nj][0] = 0; ///blue
    //                 }
    //             }
    //         }            
    //     }
    // }
    
    char str[20] = "x*x*x+77-8*x+5/2";
    // printf("%c -- %d\n", str[strlen(str)],strlen(str));
    
    // printf("%d\n", sizeof(int));

    // int **arr = (int **)malloc(3 * sizeof(int *));
    // for (int i=0; i<3; i++)
    //      arr[i] = (int *)malloc(4 * sizeof(int));
    // arr[0][0] = 1;
    // printf("%d\n",  arr[0][0]);

    // char* ptr;
    // printf("input: %s\n", str);
    // substitui(str);
    // strtol("x*x*x+7-8*x+5/2", &ptr,0);
    // transform(str);
    // printf("atoi -- %d\n",atoi("123456+78910-111213"));
    //3x^2+5x+7
    coordinate* a = threads(range/2,-range/2,1,3,0);
    coordinate* b = calcular(range/2,-range/2,0,2,0);

    // for(int i =0; i < range; i++){
    //     if(a[i].x != b[i].x || a[i].y != b[i].y){
    //         printf("seq: [%d, %d]\n", b[i].x, b[i].y);
    //         printf("thread: [%d, %d]\n", a[i].x, a[i].y);
    //     }
    // }
    
    //generateBitmapImage(a, range, range, imageFileName);
    
    threadBMP(a, range, range);
    printf("Image generated!\n");

}