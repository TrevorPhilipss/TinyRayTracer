#pragma once
#include <glm/vec3.hpp>

namespace TinyRT {
    class Ray {
    public:
        Ray();
        Ray(const glm::vec3& origin, const glm::vec3& direction);

        glm::vec3 origin() const;
        glm::vec3 direction() const;

    private:
        glm::vec3 orig;
        glm::vec3 dir;
    };
}
