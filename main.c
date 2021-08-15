#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bmp.h"

int main(int argc, char* argv[])
{   
    
    int height = 500;
    int width  = 500;
    if(argc > 2){
        height = atoi(argv[1]);
        width = atoi(argv[2]);        
    }
    
    unsigned char image[height][width][BYTES_PER_PIXEL];
    char* imageFileName;

    sprintf(imageFileName,"%dx%d.bmp",width,height);

    int i, j;
    int nj,ni;
    for (i = -height/2; i < height/2; i++) {
        for (j = -width/2; j < (width/2); j++) {
            if(i==(j*j+20*j+20)){
                if(j < 0){
                    nj = (width/2)-abs(j);
                    if(i<0){
                        ni = (height/2)-abs(i);                        
                        image[ni][nj][2] = 255; ///red
                        image[ni][nj][1] = 0; ///green
                        image[ni][nj][0] = 0; ///blue
                    }                    
                    else{
                        ni = i+(height/2);
                        image[ni][nj][2] = 255; ///red
                        image[ni][nj][1] = 0; ///green
                        image[ni][nj][0] = 0; ///blue
                    }
                }
                else{
                    nj = j+width/2;
                    if(i<0){
                        ni = (height/2)-abs(i);
                        image[ni][nj][2] = 255; ///red
                        image[ni][nj][1] = 0; ///green
                        image[ni][nj][0] = 0; ///blue
                    }
                    else{
                        ni = i+(height/2);
                        image[ni][nj][2] = 255; ///red
                        image[ni][nj][1] = 0; ///green
                        image[ni][nj][0] = 0; ///blue
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
                        if(i == 0 || j == 0){
                            image[i+(height/2)][(width/2)-abs(j)][2] = 119; ///red
                            image[i+(height/2)][(width/2)-abs(j)][1] = 136; ///green
                            image[i+(height/2)][(width/2)-abs(j)][0] = 153; ///blue
                        }
                        else{
                            image[i+(height/2)][(width/2)-abs(j)][2] = 255; ///red
                            image[i+(height/2)][(width/2)-abs(j)][1] = 255; ///green
                            image[i+(height/2)][(width/2)-abs(j)][0] = 255; ///blue
                        }
                    }
                }
                else{
                    if(i<0){
                        if(j == 0){
                            image[(height/2)-abs(i)][j+width/2][2] = 119; ///red
                            image[(height/2)-abs(i)][j+width/2][1] = 136; ///green
                            image[(height/2)-abs(i)][j+width/2][0] = 153; ///blue
                        }
                        else{
                            image[(height/2)-abs(i)][j+width/2][2] = 255; ///red
                            image[(height/2)-abs(i)][j+width/2][1] = 255; ///green
                            image[(height/2)-abs(i)][j+width/2][0] = 255; ///blue
                        }
                        
                    }
                    else{
                        if(i == 0 || j == 0){
                            image[i+(height/2)][j+width/2][2] = 119; ///red
                            image[i+(height/2)][j+width/2][1] = 136; ///green
                            image[i+(height/2)][j+width/2][0] = 156; ///blue
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
    }

    generateBitmapImage((unsigned char*) image, height, width, imageFileName);
    printf("%s generated!\n", imageFileName);
}