/*
    library created to create a bitmap image and draw the equation
    following the https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html web site structure
*/

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include <pthread.h>
#include "../lib/bmp.h"
#include "../lib/threadvariables.h"

unsigned char* createBitmapFileHeader (int height, int stride);
unsigned char* createBitmapInfoHeader (int height, int width);
void drawImage(int height, int width, char* imageFileName);

unsigned char gImage[500][500][BYTES_PER_PIXEL];
point* coor;
int gHeight;
int gWidth;

void* taskBMP(void*arg){
    long long int id = (long long int) arg;

    printf("Entrei na task %d\n", id);
    
    

    // int i = gXMin < 0 ? (id - abs(gXMin)) : gXMin - id;
    
    for(int i = id-gWidth/2; i < gWidth/2; i+=NTHREADS){
        //here we verify if the values fit to the size of the array(gHeight)
        if(
        coor[i+gWidth/2].y+gHeight/2 > gHeight ||
        coor[i+gWidth/2].x+gWidth/2 > gWidth ||
        i+gHeight/2 > gHeight
        ) continue;
        
        if(coor[i+gWidth/2].y+gHeight/2 > 0){
            //draw the points
            gImage[coor[i+gWidth/2].y+gHeight/2][coor[i+gWidth/2].x+gWidth/2][2] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2][coor[i+gWidth/2].x+gWidth/2][1] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2][coor[i+gWidth/2].x+gWidth/2][0] = 0;
            
            gImage[coor[i+gWidth/2].y+gHeight/2][coor[i+gWidth/2].x+gWidth/2+1][2] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2][coor[i+gWidth/2].x+gWidth/2+1][1] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2][coor[i+gWidth/2].x+gWidth/2+1][0] = 0;

            gImage[coor[i+gWidth/2].y+gHeight/2+1][coor[i+gWidth/2].x+gWidth/2][2] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2+1][coor[i+gWidth/2].x+gWidth/2][1] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2+1][coor[i+gWidth/2].x+gWidth/2][0] = 0;

            gImage[coor[i+gWidth/2].y+gHeight/2+1][coor[i+gWidth/2].x+gWidth/2+1][2] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2+1][coor[i+gWidth/2].x+gWidth/2+1][1] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2+1][coor[i+gWidth/2].x+gWidth/2+1][0] = 0;

            gImage[coor[i+gWidth/2].y+gHeight/2-1][coor[i+gWidth/2].x+gWidth/2][2] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2-1][coor[i+gWidth/2].x+gWidth/2][1] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2-1][coor[i+gWidth/2].x+gWidth/2][0] = 0;

            gImage[coor[i+gWidth/2].y+gHeight/2][coor[i+gWidth/2].x+gWidth/2-1][2] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2][coor[i+gWidth/2].x+gWidth/2-1][1] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2][coor[i+gWidth/2].x+gWidth/2-1][0] = 0;

            gImage[coor[i+gWidth/2].y+gHeight/2-1][coor[i+gWidth/2].x+gWidth/2-1][2] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2-1][coor[i+gWidth/2].x+gWidth/2-1][1] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2-1][coor[i+gWidth/2].x+gWidth/2-1][0] = 0;

            gImage[coor[i+gWidth/2].y+gHeight/2+1][coor[i+gWidth/2].x+gWidth/2-1][2] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2+1][coor[i+gWidth/2].x+gWidth/2-1][1] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2+1][coor[i+gWidth/2].x+gWidth/2-1][0] = 0;
            
            gImage[coor[i+gWidth/2].y+gHeight/2-1][coor[i+gWidth/2].x+gWidth/2+1][2] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2-1][coor[i+gWidth/2].x+gWidth/2+1][1] = 0;
            gImage[coor[i+gWidth/2].y+gHeight/2-1][coor[i+gWidth/2].x+gWidth/2+1][0] = 0;            
        }
    }
    pthread_exit(NULL);
}

void concurrentyGenerateBitmapImage (point* points,int height, int width){    
    gHeight = height;
    gWidth = width;
    // unsigned char image[height][width][BYTES_PER_PIXEL];
    // gImage = (unsigned char***) malloc(sizeof(unsigned char **)*gHeight);
    //  for (int i = 0; i < gHeight; i++){        
    //     gImage[i] = (unsigned char **) malloc (sizeof(unsigned char *) *gWidth);        
    //     if(gImage[i] == NULL){
    //         printf("ERROR... malloc");
    //         exit(1);
    //     }        
    //     for (int j = 0; j < gWidth; j++){
    //         gImage[i][j] = (unsigned char *) malloc (sizeof(unsigned char) *BYTES_PER_PIXEL);
    //         if(gImage[i][j] == NULL){
    //             printf("ERROR... malloc");
    //             exit(1);
    //         }
    //     }
    // }
    // gImage = image;
    
    
    //Paint the canvas
    for(int i = 0;i<gHeight;i++){       
        for(int j = 0; j< gWidth;j++){
            if(j == gWidth/2 || i == gHeight/2){               
                gImage[i][j][2] = 119; ///red
                gImage[i][j][1] = 136; ///blue
                gImage[i][j][0] = 153; ///green
            }
            else{
                gImage[i][j][2] = 255; ///red
                gImage[i][j][1] = 255; ///blue
                gImage[i][j][0] = 255; ///green
            }
        }
    }
    coor = (point*) malloc(sizeof(point)*width);
    if(coor == NULL){
        printf("ERROR... malloc");
        exit(1);        
    }
    coor = points;

    char* imageFileName;
    imageFileName = (char*) malloc(sizeof(int)*2 + sizeof(char)*5);
    if(imageFileName == NULL){
        printf("ERROR... malloc");
        exit(1);
    }
    sprintf(imageFileName,"%dx%d.bmp",gWidth,gHeight);
    
    pthread_t *tid = (pthread_t *) malloc (sizeof(pthread_t) *NTHREADS);
    if(tid == NULL){
        printf("ERROR... malloc");
        exit(1);
    }
     
    for (int i = 0; i < NTHREADS; i++){
        if(pthread_create(tid+i, NULL, taskBMP, (void *)i)){
            printf("ERROR... pthread_create");
            exit(2);
        }
    }
    

    for (int i = 0; i < NTHREADS; i++){
        if(pthread_join(*(tid+i), NULL)){
            printf("ERROR... pthread_join");
            exit(3);
        }
    }    
    
    drawImage(height, width, imageFileName);
}

void drawImage(int height, int width, char* imageFileName){
    
    
    unsigned char* img = (unsigned char*) gImage;
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

void generateBitmapImage (point* coor,int height, int width, char* imageFileName)
{

    unsigned char image[height][width][BYTES_PER_PIXEL];
    // unsigned char*** image;
    //alocando dinamicamente as variáveis height, width e BYTES_PER_PIXEL
    // image = (unsigned char ***) malloc (sizeof(unsigned char **) *height);
    // if(image == NULL){
    //     printf("ERROR... malloc");
    //     exit(1);
    // }

    // for (int i = 0; i < height; i++){
    //     image[i] = (unsigned char **) malloc (sizeof(unsigned char *) *width);
    //     if(image[i] == NULL){
    //         printf("ERROR... malloc");
    //         exit(1);
    //     }
    //     for (int j = 0; j < width; j++){
    //         image[i][j] = (unsigned char *) malloc (sizeof(unsigned char) *BYTES_PER_PIXEL);
    //         if(image[i][j] == NULL){
    //             printf("ERROR... malloc");
    //             exit(1);
    //         }
    //     }
    // }

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

    printf("%d\n", image[0][0][0]);
    
    for(int i = -width/2; i < width/2; i++){
        //here we verify if the values fit to the size of the array(height)
        if(
        coor[i+width/2].y+height/2 > height ||
        coor[i+width/2].x+width/2 > width ||
        i+height/2 > height
        ) continue;
        
        if(coor[i+width/2].y+height/2 > 0){                

            image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2][2] = 0;
            image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2][1] = 0;
            image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2][0] = 0;
            
            image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2+1][2] = 0;
            image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2+1][1] = 0;
            image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2+1][0] = 0;

            image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2][2] = 0;
            image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2][1] = 0;
            image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2][0] = 0;

            image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2+1][2] = 0;
            image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2+1][1] = 0;
            image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2+1][0] = 0;

            image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2][2] = 0;
            image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2][1] = 0;
            image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2][0] = 0;

            image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2-1][2] = 0;
            image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2-1][1] = 0;
            image[coor[i+width/2].y+height/2][coor[i+width/2].x+width/2-1][0] = 0;

            image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2-1][2] = 0;
            image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2-1][1] = 0;
            image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2-1][0] = 0;

            image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2-1][2] = 0;
            image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2-1][1] = 0;
            image[coor[i+width/2].y+height/2+1][coor[i+width/2].x+width/2-1][0] = 0;
            
            image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2+1][2] = 0;
            image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2+1][1] = 0;
            image[coor[i+width/2].y+height/2-1][coor[i+width/2].x+width/2+1][0] = 0;            
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