#pragma once

#include "material.h"
#include "vec3.h"

class Lambertian : public Material
{
public:
	Lambertian(const Vec3& albedo) : albedo_(albedo) {}

	virtual bool scatter(
		const Ray& inRay, const HitResult& hitResult,
		Vec3& outAttenuation, Ray& outScatteredRay) const override;

public:
	Vec3 albedo_ = Vec3::ZeroVec;
};

