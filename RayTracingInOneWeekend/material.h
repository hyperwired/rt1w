#pragma once

#include "hittable.h"
#include "ray.h"
#include "vec3.h"

class Material
{
public:
	virtual bool scatter(const Ray& inRay, const HitResult& hitResult, 
		Vec3& outAttenuation, Ray& outScatteredRay) const = 0;
};

