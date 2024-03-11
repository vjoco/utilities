#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to convert YUV (NV12 or NV21) to RGB24
void yuv_to_rgb24(unsigned char rgb[], unsigned char yuv[], int width, int height, size_t prerow, bool isNV12) {
    int total = prerow * height;
    int Y, U, V;
    int R, G, B;
    int index = 0;
    
    for (int h = 0; h < height; h++) {
        unsigned char *yBufferLine = &yuv[h * prerow];
        unsigned char *uvdataLine = &yuv[total + (h >> 1) * prerow];
        
        for (int w = 0; w < width; w++) {
            Y = yBufferLine[w];
            if (isNV12) {
                U = uvdataLine[w & ~1];
                V = uvdataLine[w | 1];
            } else {
                V = uvdataLine[w & ~1];
                U = uvdataLine[w | 1];
            }
            
            R = Y + 1.402 * (V - 128);
            G = Y - 0.344 * (U - 128) - 0.714 * (V - 128);
            B = Y + 1.772 * (U - 128);
            
            if (R < 0) R = 0; else if (R > 255) R = 255;
            if (G < 0) G = 0; else if (G > 255) G = 255;
            if (B < 0) B = 0; else if (B > 255) B = 255;
            
            rgb[index++] = (unsigned char)B;
            rgb[index++] = (unsigned char)G;
            rgb[index++] = (unsigned char)R;
        }
    }
}

// Function to write RGB24 data to a BMP file
// Function to write RGB24 data to a BMP file
void write_bmp(const char *filename, unsigned char *rgb_data, int width, int height) {
    int filesize = 54 + 3 * width * height;
    unsigned char bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    unsigned char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    unsigned char bmppad[3] = {0, 0, 0};

    bmpfileheader[2] = (unsigned char) (filesize);
    bmpfileheader[3] = (unsigned char) (filesize >> 8);
    bmpfileheader[4] = (unsigned char) (filesize >> 16);
    bmpfileheader[5] = (unsigned char) (filesize >> 24);

    bmpinfoheader[4] = (unsigned char) (width);
    bmpinfoheader[5] = (unsigned char) (width >> 8);
    bmpinfoheader[6] = (unsigned char) (width >> 16);
    bmpinfoheader[7] = (unsigned char) (width >> 24);
    bmpinfoheader[8] = (unsigned char) (height);
    bmpinfoheader[9] = (unsigned char) (height >> 8);
    bmpinfoheader[10] = (unsigned char) (height >> 16);
    bmpinfoheader[11] = (unsigned char) (height >> 24);

    FILE *file = fopen(filename, "wb");
    fwrite(bmpfileheader, 1, 14, file);
    fwrite(bmpinfoheader, 1, 40, file);
    for (int i = 0; i < height; i++) {
        fwrite(rgb_data + (width * (height - i - 1) * 3), 3, width, file);
        fwrite(bmppad, 1, (4 - (width * 3) % 4) % 4, file);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s input_file output_file width height\n", argv[0]);
        return -1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int width = atoi(argv[3]);
    int height = atoi(argv[4]);

    FILE *file = fopen(input_file, "rb");
    if (!file) {
        printf("Error opening input file.\n");
        return -1;
    }

    size_t prerow = width;
    unsigned char *yuv_data = (unsigned char *)malloc(prerow * height * 3 / 2);
    if (!yuv_data) {
        printf("Error allocating memory.\n");
        fclose(file);
        return -1;
    }

    fread(yuv_data, sizeof(unsigned char), prerow * height * 3 / 2, file);
    fclose(file);

    unsigned char *rgb_data = (unsigned char *)malloc(width * height * 3);
    if (!rgb_data) {
        printf("Error allocating memory.\n");
        free(yuv_data);
        return -1;
    }

    // Perform conversion
    yuv_to_rgb24(rgb_data, yuv_data, width, height, prerow, true); // Assuming NV12 format

    // Write RGB24 data to output file
    write_bmp(output_file, rgb_data, width, height);

    // Free allocated memory
    free(yuv_data);
    free(rgb_data);

    return 0;
}
