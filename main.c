#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bmp.h"

int main ()
{
    int height = 200;
    int width  = 200;
    unsigned char image[height][width][BYTES_PER_PIXEL];
    char* imageFileName;

    sprintf(imageFileName,"%dx%d.bmp",width,height);

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = -width/2; j < (width/2); j++) {
            if(i==(j*j)){
                if(j < 0){
                    image[i][(width/2)-abs(j)][2] = 255; ///red
                    image[i][(width/2)-abs(j)][1] = 0; ///green
                    image[i][(width/2)-abs(j)][0] = 0; ///blue
                }
                else{
                    image[i][j+width/2][2] = 255; ///red
                    image[i][j+width/2][1] = 0; ///green
                    image[i][j+width/2][0] = 0; ///blue
                }
            }
            else{
                if(j < 0){
                    image[i][(width/2)-abs(j)][2] = 255; ///red
                    image[i][(width/2)-abs(j)][1] = 255; ///green
                    image[i][(width/2)-abs(j)][0] = 255; ///blue
                }
                else{
                    image[i][j+width/2][2] = 255; ///red
                    image[i][j+width/2][1] = 255; ///green
                    image[i][j+width/2][0] = 255; ///blue
                }
            }
        }
    }

    generateBitmapImage((unsigned char*) image, height, width, imageFileName);
    printf("Image generated!!\n");
}