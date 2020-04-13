#pragma once
#include "material.h"

class Metal : public Material
{
public:
	Metal(const Vec3& albedo, float fuzziness);

	virtual bool scatter(
		const Ray& inRay, const HitResult& hitResult,
		Vec3& outAttenuation, Ray& outScatteredRay) const override;

public:
	Vec3 albedo_ = Vec3::ZeroVec;
	float fuzziness_ = 0.f;
};

