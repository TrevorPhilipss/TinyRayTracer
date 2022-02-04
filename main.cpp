#include <iostream>
#include "ppm.h"
#include "ray.h"
#include "primitives.h"
#include "rayCone.h"
#include "rayTracer.h"
#include "utils.h"
#include "glm/gtc/matrix_transform.hpp"

using namespace TinyRT;

std::vector<glm::vec3> cube_vertex = {
        {-0.5,-0.5,0.5},
         {0.5,-0.5,0.5},
        {0.5,-0.5,-0.5},
        {-0.5,-0.5,-0.5},

        {-0.5,0.5,0.5},
        {0.5,0.5,0.5},
        {0.5,0.5,-0.5},
        {-0.5,0.5,-0.5}
};

std::vector<int> cube_index = {
        0,2,1,
        0,3,2,

        4,5,6,
        4,6,7,

        0,1,5,
        0,5,4,

        3,6,2,
        3,7,6,

        1,2,6,
        1,6,5,

        0,4,3,
        3,4,7

};


int main() {

    auto  rotateMat = glm::rotate(glm::mat4(1.0f), glm::radians(35.0f), glm::vec3(0.4,1,0.2)) ;
    auto  moveMat   = glm::translate(glm::mat4(1.0f), glm::vec3(0,0,-3));


    auto pList = GetPrimitivesList(cube_vertex, cube_index, moveMat*rotateMat*glm::mat4(5.0f));


    RayCone rayCone(1920, 1080,new SimpleTracer(new BasicSampler()), 45.0f, true);

    rayCone.render(pList, glm::mat4(1.0f));

    rayCone.getImage().save("box.ppm");

    return 0;
}
