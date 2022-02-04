#pragma once
#include "ppm.h"
#include "ray.h"
#include "primitives.h"

namespace TinyRT {
    class BasicSampler {
    public:
        ~BasicSampler(){}

        PPMColor sampling(const Ray& ray, const Primitives& primitives, const IntersectTestResult& res, void* optional);
    };
}