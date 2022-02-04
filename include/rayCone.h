#pragma once
#include "ppm.h"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "primitives.h"
#include "rayTracer.h"
#include <vector>
#include <memory>

namespace TinyRT {

    class RayCone {
    public:
        RayCone(int width, int height, RayTracer* t, float fov = 45.0f,bool antiAliasing = true, float d = 1);
        ~RayCone();

        PPMImage& getImage();

        void render(std::vector<Primitives> p, glm::mat4 transform);

    private:
        PPMImage image;
        int Width;
        int Height;
        float Fov;
        float distance;
        std::shared_ptr<RayTracer> pTracer;
        bool AntiAliasing;
    };
}