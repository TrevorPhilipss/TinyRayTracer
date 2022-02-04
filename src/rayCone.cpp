#include "rayCone.h"

namespace TinyRT {
    RayCone::RayCone(int width, int height, RayTracer* t, float fov,bool antiAliasing, float d) :
        Width(width), Height(height), Fov(fov), distance(d), image(width, height), pTracer(t), AntiAliasing(antiAliasing){
        if(antiAliasing) {
            //x16 antiAliasing
            Width  *= 4;
            Height *= 4;
            image = PPMImage(Width, Height);
        }
    }

    RayCone::~RayCone() {

    }

    PPMImage & RayCone::getImage() {
        return image;
    }

    void RayCone::render(std::vector<Primitives> p, glm::mat4 transform) {
        float aspect = (float)Width / (float)Height;

        float viewHeight = distance * glm::tan(glm::radians(Fov / 2.0f)) * 2.0f;
        float viewWidth  = aspect * viewHeight;




        glm::vec3 LeftTop = glm::vec3(-viewWidth / 2.0f, viewHeight / 2.0f, -distance);
        glm::vec3 verticalRate = glm::vec3(0, viewHeight / Height, 0);
        glm::vec3 horizontalRate = glm::vec3(viewWidth / Width, 0, 0);

#pragma omp parallel for
        for(int j = 0; j < Height; j++) {
            for(int i = 0; i < Width; i++) {

                glm::vec3 pixelPoint = LeftTop + horizontalRate * (float)i - verticalRate * (float)j;

                Ray ray(glm::vec3(0,0,0), pixelPoint);
                image(j, i) = pTracer->trace(ray, p, transform);
            }
        }

        //antiAliasing
        if(AntiAliasing) {
            PPMImage antiAliasingImage(Width / 4, Height / 4);
            for (int j = 0; j < Height; j += 4) {
                for (int i = 0; i < Width; i += 4) {
                    float r = 0, g = 0, b = 0;

                    for (int jj = 0; jj < 4; jj++) {
                        for (int ii = 0; ii < 4; ii++) {
                            r += image(j + jj, i + ii).r;
                            g += image(j + jj, i + ii).g;
                            b += image(j + jj, i + ii).b;

                        }
                    }

                    r /= 16.0f;
                    if (r > 1.0f) r = 1.0f;

                    g /= 16.0f;
                    if (g > 1.0f) g = 1.0f;

                    b /= 16.0f;
                    if (b > 1.0f) b = 1.0f;

                    antiAliasingImage(j / 4, i / 4) = {r, g, b};

                }
            }

            image = antiAliasingImage;
        }
    }

}