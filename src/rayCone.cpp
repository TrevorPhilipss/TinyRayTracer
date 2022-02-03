#include "rayCone.h"

namespace TinyRT {
    RayCone::RayCone(int width, int height, RayTracer* t, float fov, float d) :
        Width(width), Height(height), Fov(fov), distance(d), image(width, height), tracer(t){
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
                image(j, i) = tracer->trace(ray, p, transform);
            }
        }
    }

}