#include "rayTracer.h"

namespace TinyRT {

    class SimpleRayTracer : public RayTracer {
    public:
        virtual PPMColor trace(const Ray& ray, const std::vector<Primitives> p, glm::mat4 transform) {
            IntersectTestResult bestResult;
            bestResult.distance = 9999999.0f;

            for(auto i : p) {
                i.V0 = glm::vec4(i.V0, 1.0f) * transform;
                i.V1 = glm::vec4(i.V1, 1.0f) * transform;
                i.V2 = glm::vec4(i.V2, 1.0f) * transform;
                auto temp = i.intersectTest(ray, 1.0f);
                if(temp.Intersected && temp.distance < bestResult.distance) {
                    bestResult = temp;
                }

            }

            if(bestResult.distance < 9999999.0f) {
                float dt = glm::dot(-ray.direction(), bestResult.ReflectionDirection);
                if(dt > 1) dt = 1;
                dt = glm::pow(dt, 0.5f);
                auto color = glm::vec3(0.8,0.4,0.3) * dt;
                return {color.x, color.y, color.z};
            } else {
                return {0,0,0};
            }
        }
    };

    RayTracer * RayTracerFactory::GetSimpleTracer() {
        return new SimpleRayTracer();
    }
}