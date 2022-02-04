#include "primitives.h"
#include <glm/gtc/matrix_transform.hpp>
namespace TinyRT {

    IntersectTestResult Primitives::intersectTest(const Ray &ray, float refractiveIndex) {
        glm::vec3 normal = glm::normalize(glm::cross(V1-V0, V2-V1));
        float A = normal.x;
        float B = normal.y;
        float C = normal.z;
        float D = -A*V0.x - B * V0.y - C * V0.z;
        //Plane equation: Ax + By + Cz + D = 0

        glm::vec3 rayOrigin = ray.origin();
        glm::vec3 rayDirection = glm::normalize(ray.direction());

        float t = -(D + A * rayOrigin.x + B * rayOrigin.y + C * rayOrigin.z) /
                    (A * rayDirection.x + B * rayDirection.y + C * rayDirection.z);

        //check if ray intersect with plant
        if(t <= 0 || glm::dot(rayDirection , normal) >= 0) {
            IntersectTestResult result;
            result.Intersected = false;
            return result;
        }

        glm::vec3 intersectedPoint = rayOrigin + rayDirection * t;
        //check if intersect point is in triangle
        glm::vec3 PV0 = V0 - intersectedPoint;
        glm::vec3 PV1 = V1 - intersectedPoint;
        glm::vec3 PV2 = V2 - intersectedPoint;

        float S0 = glm::length(glm::cross(V1-V0, V2-V0));
        float S1 = glm::length(glm::cross(PV0, PV1)) +
                glm::length(glm::cross(PV0, PV2)) +
                glm::length(glm::cross(PV1, PV2));


        IntersectTestResult result;
        result.distance = t;

        if(abs(S0-S1)<0.0001) {
            result.Intersected = true;
            result.IntersectedPoint = intersectedPoint;
            result.PrimitivesNormal = normal;
            result.ReflectionDirection = -glm::normalize(glm::reflect(normal, ray.direction()));
            //TODO:RefractionDirection


            return result;
        } else {
            result.Intersected = false;
            return result;
        }

    }
}

