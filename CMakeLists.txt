cmake_minimum_required(VERSION 3.19)
project(TinyRayTracer)
find_package(OpenMP REQUIRED)
set(CMAKE_CXX_STANDARD 14)

add_executable(TinyRayTracer main.cpp include/ppm.h src/ppm.cpp include/ray.h include/primitives.h src/primitives.cpp src/ray.cpp include/rayCone.h src/rayCone.cpp include/rayTracer.h src/rayTracer.cpp include/utils.h src/utils.cpp)
target_include_directories(TinyRayTracer PUBLIC include "C:\\Users\\zhouy\\source\\repos\\cloth\\cloth\\glm\\glm")
target_link_libraries(TinyRayTracer PUBLIC OpenMP::OpenMP_CXX)