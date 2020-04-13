#include "lambertian.h"

#include "math_util.h"

#include <cassert>

enum class DiffuseScatterMode
{
	// A true Lambertian distribution is cos(theta), which is a more uniform distribution
	// (random point on reflected unit sphere surface with center at hit unit normal)
	TrueLambertian,
	// Bounce diffuse approximation (random point in reflected unit sphere with center at surface unit normal)
	// This distribution scales by cos^3(theta) where theta is the angle from the normal
	LambertianApprox1,
	// Uniform scatter direction for all angles away from hit point, disregarding angle from normal offset.
	// This is a simplification that used to be popular in earlier literature.
	HemisphericalApprox1,
};

Vec3 MakeDiffuseScatteringRayTarget(const HitResult& hitResult, DiffuseScatterMode diffuseMode)
{
	switch (diffuseMode)
	{
	case DiffuseScatterMode::TrueLambertian:
	{
		return hitResult.pos_ + hitResult.normal_ + randomUnitVectorSphereSurface();
	}
	case DiffuseScatterMode::LambertianApprox1:
	{
		return hitResult.pos_ + hitResult.normal_ + randomVecInUnitSphere();
	}
	case DiffuseScatterMode::HemisphericalApprox1:
	{
		return hitResult.pos_ + randomUnitVectorInHemisphere(hitResult.normal_);
	}
	default:
		assert(false && "unexpected enum value");
		return Vec3::ZeroVec;
	}
}

bool Lambertian::scatter(
	const Ray& inRay, const HitResult& hitResult,
	Vec3& outAttenuation, Ray& outScatteredRay) const
{
	// We can either:
	// - scatter always and attenuate by reflectance R
	// - scatter with no attenuation but absorb the fraction (1 - R) of rays
	// ... or a mixture of both strategies

	// Bounce diffuse 
	const DiffuseScatterMode scatterMode = DiffuseScatterMode::TrueLambertian;
	const Vec3 DiffuseBounceTarget = MakeDiffuseScatteringRayTarget(hitResult, scatterMode);
	outScatteredRay = Ray(hitResult.pos_, DiffuseBounceTarget - hitResult.pos_);
	outAttenuation = albedo_;
	return true;
}
