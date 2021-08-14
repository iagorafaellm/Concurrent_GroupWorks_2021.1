#include <stdio.h>
#include <stdlib.h>
int main() {
    int width = 1; 
    int height = 1;
    char tag[] = { 'B', 'M' };
    int header[] = {
        0x3a, 0x00, 0x36, 0x28, width, height, 0x180001, 
        0, 0, 0x002e23, 0x002e23, 0, 0 
    };

    // Store as char array, because we want each value to take up
    // one byte.
    char bitmap[] = {
        0x35, // Blue
        0x41, // Green
        0xef, // Red
        0x00  // Padding
    };
    char fr[] = {
        0, 85, 164,    // Bleu
        255, 255, 255, // Blanc
        239, 65, 53,   // Rouge
        0, 85, 164,
        255, 255, 255,
        239, 65, 53,
    };

    FILE *fp = fopen("test.bmp", "wb");
    fwrite(&tag, sizeof(tag), 1, fp);
    fwrite(&header, sizeof(header), 1, fp); 
    fwrite(&fr, sizeof(fr), 1, fp);
    fclose(fp);
}