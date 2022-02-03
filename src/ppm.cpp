#include "ppm.h"
#include <cstring>
#include <cstdio>
namespace TinyRT {

    PPMImage::PPMImage(int width, int height) {
        Width  = width;
        Height = height;
        pData  = new PPMColor[width * height];

        //a black image
        memset(pData, 0, sizeof(PPMColor) * width * height);
    }

    PPMImage::~PPMImage() {
        delete[] pData;
    }

    void PPMImage::save(const char *path) {
        FILE* file = fopen(path, "w");
        fprintf(file, "P3\n%d %d\n255\n", Width, Height);

        for (int j = 0; j < Height; j++) {
            for (int i = 0; i < Width; i++) {
                PPMColor color = pData[j * Width + i];
                int r = static_cast<int>(color.r * 255);
                int g = static_cast<int>(color.g * 255);
                int b = static_cast<int>(color.b * 255);

                if(i == Width - 1)
                    fprintf(file, "%d %d %d\n", r, g, b);
                else
                    fprintf(file, "%d %d %d ", r, g, b);
            }
        }

        fclose(file);
    }

    PPMColor & PPMImage::operator()(int row, int col) {
        return pData[row * Width + col];
    }

}
