#pragma once
#include "material.h"

class Metal : public Material
{
public:
	Metal(const Vec3& albedo) : albedo_(albedo) {}

	virtual bool scatter(
		const Ray& inRay, const HitResult& hitResult,
		Vec3& outAttenuation, Ray& outScatteredRay) const override;

public:
	Vec3 albedo_ = Vec3::ZeroVec;
};

