#pragma once
#include "primitives.h"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include <vector>

namespace TinyRT {
    std::vector<Primitives> GetPrimitivesList(std::vector<glm::vec3> vertex, std::vector<int> index, glm::mat4 transformer);
}