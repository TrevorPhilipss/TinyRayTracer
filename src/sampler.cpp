#include "sampler.h"
#include "glm/mat4x4.hpp"
namespace TinyRT {
    PPMColor BasicSampler::sampling(const Ray &ray, const Primitives &primitives, const IntersectTestResult &res,
                                    void *optional) {
        float dt = glm::dot(-ray.direction(), res.PrimitivesNormal);
        if(dt > 1) dt = 1;
        dt = glm::pow(dt, 0.5f);
        auto color = glm::vec3(0.8,0.4,0.3) * dt;
        return {color.x, color.y, color.z};
    }
}