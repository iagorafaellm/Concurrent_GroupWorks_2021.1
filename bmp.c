/*
    library created to create a bitmap image and draw the equation
    following the https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html web site structure
*/

#include <stdio.h>
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
