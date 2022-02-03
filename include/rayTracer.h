#pragma once
#include "primitives.h"
#include "ppm.h"
#include "ray.h"
#include "glm/mat4x4.hpp"
#include <vector>
namespace TinyRT {
    class RayTracer {
    public:
        virtual ~RayTracer(){}
        virtual PPMColor trace(const Ray& ray, const std::vector<Primitives> p, glm::mat4 transform) = 0;
    };

    class RayTracerFactory {
    public:
       static RayTracer* GetSimpleTracer();
    };
}