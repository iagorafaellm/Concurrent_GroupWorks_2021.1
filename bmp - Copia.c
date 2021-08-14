/*
    library created to create a bitmap image and draw the equation
    following the https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html web site structure
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdint.h>
#define FILEHEADERSIZE 14 
#define INFOHEADERSIZE 40
#define BYTESPERPIXEL  3 /// red, green and blue

typedef struct{
    char bfType[2];         /// must always be set to 'BM' to declare that this is a .bmp-file.
    unsigned int bfSize;    ///	specifies the size of the file in bytes.
    short int bfReserved1;  /// must always be set to zero.
    short int bfReserved2;  /// must always be set to zero.
    unsigned int bfOffBits; /// specifies the offset from the beginning of the file to the bitmap data.
}fileHeader;

typedef struct{
    unsigned int biSize;          /// specifies the size of the BITMAPINFOHEADER structure, in bytes.
    unsigned int biWidth;         /// specifies the width of the image, in pixels.
    unsigned int biHeight;        /// specifies the height of the image, in pixels.
    short int biPlanes;           /// specifies the number of planes of the target device, must be set to zero.
    short int biBitCount;         /// specifies the number of bits per pixel.
    unsigned int biCompression;   /// Specifies the type of compression, usually set to zero (no compression).
    unsigned int biSizeImage;     /// specifies the size of the image data, in bytes. If there is no compression, it is valid to set this member to zero.
    unsigned int biXPelsPerMeter; /// specifies the the horizontal pixels per meter on the designated targer device, usually set to zero.
    unsigned int biYPelsPerMeter; /// specifies the the vertical pixels per meter on the designated targer device, usually set to zero.
    unsigned int biClrUsed;       /// specifies the number of colors used in the bitmap, if set to zero the number of colors is calculated using the biBitCount member.
    unsigned int biClrImportant;  /// specifies the number of color that are 'important' for the bitmap, if set to zero, all colors are important.

}infoHeader;

typedef struct{
    fileHeader headerFile;
    infoHeader headerInfo;
}header;


fileHeader createFileHeader(unsigned int width, unsigned int height){

    fileHeader header = {     
        .bfType = "BM",
        .bfSize= (width*height) + FILEHEADERSIZE + INFOHEADERSIZE,        
        .bfReserved1 = 0,
        .bfReserved2 = 0,
        .bfOffBits = FILEHEADERSIZE + INFOHEADERSIZE
    };

    return header;
}

infoHeader createInfoHeader(unsigned int width, unsigned int height){
    infoHeader header = {
        .biSize = INFOHEADERSIZE,
        .biWidth = width,
        .biHeight = height,
        .biPlanes = 0,
        .biBitCount = BYTESPERPIXEL*8,
        .biCompression = 0,
        .biSizeImage = height*width*BYTESPERPIXEL,
        .biXPelsPerMeter = 0,
        .biYPelsPerMeter = 0,
        .biClrUsed = 0,
        .biClrImportant = 0
    };

    return header;
}

void createAndWriteHeaders(unsigned int width, unsigned int height,char*fileName){    
    char buffer[100];
    fileHeader headerFile = createFileHeader(width,height);
    infoHeader headerInfo = createInfoHeader(width,height);

    FILE* file = fopen(fileName,"wb");

    fwrite((char*)&headerFile,1,FILEHEADERSIZE,file);
    fwrite((char*)&headerInfo,1,INFOHEADERSIZE,file);
    return;
}

typedef struct{
    int blue;
    int green;
    int red;
    
} rgb;

// void generateBMPImage(char* image, unsigned int width, unsigned int height, char* fileName){
    
//     createAndWriteHeaders(width,height,fileName);

//     FILE* imgFile = fopen(fileName, "w");    
//     //fileHeader headerFile = createFileHeader(width,height);
//     //infoHeader headerInfo = createInfoHeader(width, height);    
//     // fwrite((char*)&headerFile, 1,FILEHEADERSIZE,imgFile);
//     // fwrite((char*)&headerInfo, 1,INFOHEADERSIZE,imgFile);

//     int nPixel = width*height;
//     rgb pixel = {.blue = 255, .green = 255, .red = 255};
//     rgb img[height][width];

//     rgb r[5][5];
//     //r[0][0].blue =
//     unsigned char color[100][100][3];

//     for(int i = 0; i < height;i++){
//         for(int j =0; j< width; j++){
//             if(i==j*j)
//             {
//                 color[i][j][0] = 255;
//                 color[i][j][1] = 0;
//                 color[i][j][2] = 0;
                
//             }
//             else{
//                 color[i][j][0] = 255;
//                 color[i][j][1] = 255;
//                 color[i][j][2] = 255;
                
//             }
//             fwrite(color+(i*width*BYTESPERPIXEL),1,width,imgFile);
//         }
//     }
//     //fwrite(img,BYTESPERPIXEL,width*height,imgFile);
//     // char img[3][3] = {{255,255,255},{0,0,0},{0,0,0}};
//     //fwrite("ola", BYTESPERPIXEL, width, imgFile);
//     // for(int i = 0; i< height; i++){
//     //     fwrite(img,BYTESPERPIXEL,width*height,imgFile);
//     // }
// }

void generateBitmapImage (unsigned char* image, int height, int width, char* imageFileName)
{
    int widthInBytes = width * BYTESPERPIXEL;

    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;

    int stride = (widthInBytes) + paddingSize;

    FILE* imageFile = fopen(imageFileName, "wb");

    // unsigned char* fileHeader = createBitmapFileHeader(height, stride);
    // fwrite(fileHeader, 1, FILEHEADERSIZE, imageFile);

    // unsigned char* infoHeader = createBitmapInfoHeader(height, width);
    // fwrite(infoHeader, 1, INFOHEADERSIZE, imageFile);
    createAndWriteHeaders(width,height,imageFileName);

    int i;
    for (i = 0; i < height; i++) {
        fwrite(image + (i*widthInBytes), BYTESPERPIXEL, width, imageFile);
        fwrite(padding, 1, paddingSize, imageFile);
    }

    fclose(imageFile);
}

// int main(){

//     int height = 100;
//     int width = 100;
//     // unsigned char image[height][width][BYTESPERPIXEL];
//     // int i, j;
//     // for (i = 0; i < height; i++) {
//     //     for (j = 0; j < width; j++) {
//     //         image[i][j][2] = (unsigned char) ( i * 255 / height );             ///red
//     //         image[i][j][1] = (unsigned char) ( j * 255 / width );              ///green
//     //         image[i][j][0] = (unsigned char) ( (i+j) * 255 / (height+width) ); ///blue
//     //     }
//     // }
//     char bitmap[] = {
//         0x35,
//         0x41,
//         0xef,
//         0x00
//     };
//     unsigned char color[height][width][3];
//     for(int i = 0; i < height;i++){
//         for(int j =0; j< width; j++){
//             if(i==j*j)
//             {
//                 color[i][j][0] = 255;
//                 color[i][j][1] = 0;
//                 color[i][j][2] = 0;
                
//             }
//             else{
//                 color[i][j][0] = 255;
//                 color[i][j][1] = 255;
//                 color[i][j][2] = 255;
                
//             }            
//         }
//     }

//     //generateBMPImage(bitmap,width,height,"test3.bmp");
//     generateBitmapImage((unsigned char*)color,height,width,"teste.bmp");
//     return 0;
// }

int main ()
{
    int height = 361;
    int width = 867;
    unsigned char image[height][width][BYTESPERPIXEL];
    char* imageFileName = (char*) "bitmapImage.bmp";

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if(i==j*j){
                image[i][j][2] = 255; ///red
                image[i][j][1] = 0; ///green
                image[i][j][0] = 0; ///blue
            }
            else{
                image[i][j][2] = 255; ///red
                image[i][j][1] = 255; ///green
                image[i][j][0] = 255; ///blue
            }
        }
    }

    generateBitmapImage((unsigned char*) image, height, width, imageFileName);
    printf("Image generated!!");
}

