#ifndef BMP_H

    #define BYTES_PER_PIXEL 3 /// red, green, & blue
    #define FILE_HEADER_SIZE 14 
    #define INFO_HEADER_SIZE 40

    //generate the image
    void generateBitmapImage(unsigned char* image, int height, int width, char* imageFileName);
    //create the fileHeader that is needed to create a bitmap image
    unsigned char* createBitmapFileHeader(int height, int stride);
    //create the infoHeader that is needed to create a bitmap image
    unsigned char* createBitmapInfoHeader(int height, int width);

#endif