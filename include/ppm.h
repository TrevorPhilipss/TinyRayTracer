#pragma once

namespace TinyRT {
    // a PPM image format color
    // each of the components range from 0.0 to 1.0
    struct PPMColor {
        float r, g, b;
    };

    class PPMImage {
    public:
        PPMImage(int width, int height);
        ~PPMImage();

        //save this image to file
        void save(const char* path);

        PPMColor& operator()(int row, int col);

        PPMImage& operator=(const PPMImage& image);
    private:
        int Width;
        int Height;
        PPMColor* pData;
    };

}
