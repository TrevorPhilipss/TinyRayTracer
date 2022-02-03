#include "utils.h"
#include "glm/vec4.hpp"

namespace TinyRT {
    std::vector<Primitives> GetPrimitivesList(std::vector<glm::vec3> vertex, std::vector<int> index, glm::mat4 transformer) {
        std::vector<Primitives> pList;
        for(int i = 0; i < index.size(); i+=3) {
            int index0 = index[i];
            int index1 = index[i + 1];
            int index2 = index[i + 2];

            auto v0 = vertex[index0];
            auto v1 = vertex[index1];
            auto v2 = vertex[index2];

            Primitives primitives;

            primitives.V0 = transformer*glm::vec4(v0, 1.0f);
            primitives.V1 = transformer*glm::vec4(v1, 1.0f);
            primitives.V2 = transformer*glm::vec4(v2, 1.0f);
            pList.push_back(primitives);


        }
        return pList;

    }
}
