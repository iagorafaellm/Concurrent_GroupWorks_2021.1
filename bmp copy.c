/*
    library created to create a bitmap image and draw the equation
    following the https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html web site structure
*/

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include"bmp.h"

// const int BYTES_PER_PIXEL = 3; /// red, green, & blue
// const int FILE_HEADER_SIZE = 14; 
// const int INFO_HEADER_SIZE = 40;

// void generateBitmapImage(unsigned char* image, int height, int width, char* imageFileName);
// unsigned char* createBitmapFileHeader(int height, int stride);
// unsigned char* createBitmapInfoHeader(int height, int width);

void generateBitmapImage (point* coor, int height, int width, char* imageFileName)
{
    unsigned char image[height][width][BYTES_PER_PIXEL];

    for(int i = 0;i<height;i++){
        for(int j = 0; j< width;j++){
            if(j == width/2 || i == height/2){
                image[i][j][2] = 119; ///red
                image[i][j][1] = 136; ///blue
                image[i][j][0] = 153; ///green
            }
            else{
                image[i][j][2] = 255; ///red
                image[i][j][1] = 255; ///blue
                image[i][j][0] = 255; ///green
            }
        }
    }
    if(height < width){
        for(int i = -width/2; i < width/2; i++){
            //here we verify if the values fit to the size of the array(height)
            if(
            coor[i+width/2].y+height/2 > height ||
            coor[i+width/2].x+width/2 > width ||
            i+height/2 > height
            ) continue;
            
            if(coor[i+width/2].y+height/2 > 0){

                image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2][2] = 136;
                image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2][1] = 136;
                image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2][0] = 136;
                
                // image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2+1][2] = 0;
                // image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2+1][1] = 0;
                // image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2+1][0] = 0;

                // image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2][2] = 0;
                // image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2][1] = 0;
                // image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2][0] = 0;

                // image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2+1][2] = 0;
                // image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2+1][1] = 0;
                // image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2+1][0] = 0;

                // image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2][2] = 0;
                // image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2][1] = 0;
                // image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2][0] = 0;

                // image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2-1][2] = 0;
                // image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2-1][1] = 0;
                // image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2-1][0] = 0;

                // image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2-1][2] = 0;
                // image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2-1][1] = 0;
                // image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2-1][0] = 0;

                // image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2-1][2] = 0;
                // image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2-1][1] = 0;
                // image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2-1][0] = 0;
                
                // image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2+1][2] = 0;
                // image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2+1][1] = 0;
                // image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2+1][0] = 0;
            }
            
        }
            
    }
    else{
        for(int i = -height/2; i < height/2; i++){
            //here we verify if the values fit to the size of the array(height)
            if(
            coor[i+height/2].y+height/2 > height ||
            coor[i+height/2].x+width/2 > width ||
            i+height/2 > height
            ) continue;
            
            if(coor[i+height/2].y+height/2 > 0){

                image[coor[i+height/2].y+height/2][coor[i+height/2].x+width/2][2] = 136;
                image[coor[i+height/2].y+height/2][coor[i+height/2].x+width/2][1] = 136;
                image[coor[i+height/2].y+height/2][coor[i+height/2].x+width/2][0] = 136;
                
                
            }
            
        }
    }
    for(int i = 0; i < height; i++){
        int count = 0;
        int nj;
        int pj;
        for(int j = 0; j < width; j++){
            if(coor[j].x < 0){
                if(image[i][j][0] == 136 && image[i][j][1] == 136 && image[i][j][2] == 136){
                    nj = j;                    
                }
                if(nj == j){
                    image[i][nj][0] = 0;
                    image[i][nj][1] = 0;
                    image[i][nj][2] = 0;
                  
                    image[i+1][nj][0] = 0;
                    image[i+1][nj][1] = 0;
                    image[i+1][nj][2] = 0;
                    
                    // image[i][nj-1][0] = 0;
                    // image[i][nj-1][1] = 0;
                    // image[i][nj-1][2] = 0;

                }
            }else{
                if(image[i][j][0] == 136 && image[i][j][1] == 136 && image[i][j][2] == 136){
                    pj = j;
                }
                if(pj == j){
                    
                    image[i][pj][0] = 0;
                    image[i][pj][1] = 0;
                    image[i][pj][2] = 0;

                    // image[i][pj-1][0] = 0;
                    // image[i][pj-1][1] = 0;
                    // image[i][pj-1][2] = 0;
                }
            }
                            

        }
    }

    unsigned char* img = (unsigned char*) image;
    int widthInBytes = width * BYTES_PER_PIXEL;
    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;
    //widthInBytes = (4 - (widthInBytes) % 4) % 4;

    int stride = (widthInBytes) + paddingSize;

    FILE* imageFile = fopen(imageFileName, "wb");

    unsigned char* fileHeader = createBitmapFileHeader(height, stride);
    fwrite(fileHeader, 1, FILE_HEADER_SIZE, imageFile);

    unsigned char* infoHeader = createBitmapInfoHeader(height, width);
    fwrite(infoHeader, 1, INFO_HEADER_SIZE, imageFile);

    int i;
    for (i = 0; i < height; i++) {
        fwrite(img + (i*widthInBytes), BYTES_PER_PIXEL, width, imageFile);
        if(width > height)
            fwrite(padding, 1, paddingSize, imageFile);
    }
    fclose(imageFile);
}

unsigned char* createBitmapFileHeader (int height, int stride)
{
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);

    static unsigned char fileHeader[] = {
        0,0,     /// signature - must always be set to 'BM' to declare that this is a .bmp-file.
        0,0,0,0, /// image file size in bytes - specifies the size of the file in bytes.
        0,0,0,0, /// reserved - must always be set to zero.
        0,0,0,0, /// start of pixel array - specifies the offset from the beginning of the file to the bitmap data.
    };

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize      );
    fileHeader[ 3] = (unsigned char)(fileSize >>  8);
    fileHeader[ 4] = (unsigned char)(fileSize >> 16);
    fileHeader[ 5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

    return fileHeader;
}

unsigned char* createBitmapInfoHeader (int height, int width)
{
    static unsigned char infoHeader[] = {
        0,0,0,0, /// header size - specifies the size of the BITMAPINFOHEADER structure, in bytes.
        0,0,0,0, /// image width - specifies the width of the image, in pixels.
        0,0,0,0, /// image height - specifies the height of the image, in pixels.
        0,0,     /// number of color planes - specifies the number of planes of the target device, must be set to zero.
        0,0,     /// bits per pixel - specifies the number of bits per pixel.
        0,0,0,0, /// compression - Specifies the type of compression, usually set to zero (no compression).
        0,0,0,0, /// image size - specifies the size of the image data, in bytes. If there is no compression, it is valid to set this member to zero.
        0,0,0,0, /// horizontal resolution - specifies the the horizontal pixels per meter on the designated targer device, usually set to zero.
        0,0,0,0, /// vertical resolution - specifies the the vertical pixels per meter on the designated targer device, usually set to zero.
        0,0,0,0, /// colors in color table - specifies the number of colors used in the bitmap, if set to zero the number of colors is calculated using the biBitCount member.
        0,0,0,0, /// important color count - specifies the number of color that are 'important' for the bitmap, if set to zero, all colors are important.

    };

    infoHeader[ 0] = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (unsigned char)(width      ); 
    infoHeader[ 5] = (unsigned char)(width >>  8);
    infoHeader[ 6] = (unsigned char)(width >> 16);
    infoHeader[ 7] = (unsigned char)(width >> 24);
    infoHeader[ 8] = (unsigned char)(height      );
    infoHeader[ 9] = (unsigned char)(height >>  8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);

    return infoHeader;
}