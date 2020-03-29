#pragma once

#include "hittable.h"

class Sphere : public Hittable
{
public:
	Sphere() = default;
	Sphere(const Vec3& center, float radius) : center_(center_), radius_(radius) {}
	
	virtual bool hit(const Ray& r, float t_min, float t_max, HitResult& hitResult) const override;

protected:
	HitResult makeHitResult(const Ray& r, float t) const;

public:
	Vec3 center_ = {};
	float radius_= 1.0f;
};

