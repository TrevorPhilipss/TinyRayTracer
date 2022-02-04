#include "rayTracer.h"

namespace TinyRT {

    SimpleTracer::SimpleTracer(BasicSampler *sampler) : RayTracer(sampler) {}


    PPMColor SimpleTracer::trace(const Ray& ray, const std::vector<Primitives> p, glm::mat4 transform) {
        IntersectTestResult bestResult;
        bestResult.distance = 9999999.0f;
        Primitives tempP;
        for(auto i : p) {
            i.V0 = glm::vec4(i.V0, 1.0f) * transform;
            i.V1 = glm::vec4(i.V1, 1.0f) * transform;
            i.V2 = glm::vec4(i.V2, 1.0f) * transform;
            auto temp = i.intersectTest(ray, 1.0f);
            if(temp.Intersected && temp.distance < bestResult.distance) {
                bestResult = temp;
                tempP = i;
            }

        }

        if(bestResult.distance < 9999999.0f) {
            return pSampler->sampling(ray, tempP, bestResult, nullptr);
        } else {
            return {0,0,0};
        }
    }

}