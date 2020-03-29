#pragma once

#include "ray.h"
#include "vec3.h"

struct HitResult
{
	Vec3 pos_ = {};
	Vec3 normal_ = {};
	float t_ = -1.0f;
};

class Hittable
{
public:
	virtual bool hit(const Ray& r, float t_min, float t_max, HitResult& hitResult) const = 0;
};

