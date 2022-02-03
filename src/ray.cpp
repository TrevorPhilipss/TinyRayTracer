#include "ray.h"

namespace TinyRT {
    Ray::Ray() {
    }

    Ray::Ray(const glm::vec3 &origin, const glm::vec3 &direction) : orig(origin), dir(direction){}

    glm::vec3 Ray::direction() const {
        return dir;
    }

    glm::vec3 Ray::origin() const {
        return orig;
    }
}