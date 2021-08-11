/*
    library created to create a bitmap image and draw the equation
    following the https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html web site structure
*/

#include <stdio.h>
#define FILEHEADERSIZE 14
#define INFOHEADERSIZE 40

typedef struct{
    char bfType[2]; // must always be set to 'BM' to declare that this is a .bmp-file.
    unsigned int bfSize; //	specifies the size of the file in bytes.
    short int bfReserved1; // must always be set to zero.
    short int bfReserved2; // must always be set to zero.
    unsigned int bfOffBits; // specifies the offset from the beginning of the file to the bitmap data.
}fileHeader;


typedef struct{
    unsigned int biSize; //specifies the size of the BITMAPINFOHEADER structure, in bytes.
    unsigned int biWidth; // specifies the width of the image, in pixels.
}infoHeader;



fileHeader createFileHeader(unsigned int width, unsigned int height){

    fileHeader header = {
        .bfType = "BM",
        .bfSize= (width*height) + FILEHEADERSIZE + INFOHEADERSIZE,
        .bfOffBits = FILEHEADERSIZE + INFOHEADERSIZE,
        .bfReserved1 = 0,
        .bfReserved2 = 0
    };
    
    return header;
}

