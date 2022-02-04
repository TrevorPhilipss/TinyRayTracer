#pragma once
#include "glm/vec3.hpp"
#include "ray.h"
namespace TinyRT {

    struct IntersectTestResult {
        bool      Intersected;
        float     distance;
        glm::vec3 IntersectedPoint;
        glm::vec3 PrimitivesNormal;
        glm::vec3 ReflectionDirection;
        glm::vec3 RefractionDirection;
    };

    struct Primitives {
        IntersectTestResult intersectTest(const Ray& ray, float refractiveIndex);
        glm::vec3 V0, V1, V2;
    };

}