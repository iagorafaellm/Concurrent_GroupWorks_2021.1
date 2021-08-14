#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bmp.h"

int main ()
{
    int height = 300;
    int width  = 300;
    unsigned char image[height][width][BYTES_PER_PIXEL];
    char* imageFileName;

    sprintf(imageFileName,"%dx%d.bmp",width,height);

    int i, j;
    for (i = -height/2; i < height/2; i++) {
        for (j = -width/2; j < (width/2); j++) {
            if(i==(j*j+20*j+20)){
                if(j < 0){
                    if(i<0){
                        image[(height/2)-abs(i)][(width/2)-abs(j)][2] = 255; ///red
                        image[(height/2)-abs(i)][(width/2)-abs(j)][1] = 0; ///green
                        image[(height/2)-abs(i)][(width/2)-abs(j)][0] = 0; ///blue
                    }
                    else{
                        image[i+(height/2)][(width/2)-abs(j)][2] = 255; ///red
                        image[i+(height/2)][(width/2)-abs(j)][1] = 0; ///green
                        image[i+(height/2)][(width/2)-abs(j)][0] = 0; ///blue
                    }
                }
                else{
                    if(i<0){
                        image[(height/2)-abs(i)][j+width/2][2] = 255; ///red
                        image[(height/2)-abs(i)][j+width/2][1] = 0; ///green
                        image[(height/2)-abs(i)][j+width/2][0] = 0; ///blue
                    }
                    else{
                        image[i+(height/2)][j+width/2][2] = 255; ///red
                        image[i+(height/2)][j+width/2][1] = 0; ///green
                        image[i+(height/2)][j+width/2][0] = 0; ///blue
                    }
                    
                }
            }
            else{
                if(j < 0){
                    if(i<0){
                        image[(height/2)-abs(i)][(width/2)-abs(j)][2] = 255; ///red
                        image[(height/2)-abs(i)][(width/2)-abs(j)][1] = 255; ///green
                        image[(height/2)-abs(i)][(width/2)-abs(j)][0] = 255; ///blue
                    }
                    else{
                        image[i+(height/2)][(width/2)-abs(j)][2] = 255; ///red
                        image[i+(height/2)][(width/2)-abs(j)][1] = 255; ///green
                        image[i+(height/2)][(width/2)-abs(j)][0] = 255; ///blue
                    }
                }
                else{
                    if(i<0){
                        image[(height/2)-abs(i)][j+width/2][2] = 255; ///red
                        image[(height/2)-abs(i)][j+width/2][1] = 255; ///green
                        image[(height/2)-abs(i)][j+width/2][0] = 255; ///blue
                    }
                    else{
                        image[i+(height/2)][j+width/2][2] = 255; ///red
                        image[i+(height/2)][j+width/2][1] = 255; ///green
                        image[i+(height/2)][j+width/2][0] = 255; ///blue
                    }
                }
            }
        }
    }

    generateBitmapImage((unsigned char*) image, height, width, imageFileName);
    printf("%s generated!\n", imageFileName);
}