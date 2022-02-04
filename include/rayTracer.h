#pragma once
#include "primitives.h"
#include "ppm.h"
#include "ray.h"
#include "sampler.h"
#include "glm/mat4x4.hpp"
#include <vector>
#include <memory>
namespace TinyRT {
    class RayTracer {
    public:
        RayTracer(BasicSampler* sampler) : pSampler(sampler){}
        virtual ~RayTracer(){}
        virtual PPMColor trace(const Ray& ray, const std::vector<Primitives> p, glm::mat4 transform) = 0;

    protected:
        std::shared_ptr<BasicSampler> pSampler;
    };

    class  SimpleTracer : public RayTracer {
    public:
        SimpleTracer(BasicSampler* sampler);
        virtual PPMColor trace(const Ray& ray, const std::vector<Primitives> p, glm::mat4 transform) override;
    };

}