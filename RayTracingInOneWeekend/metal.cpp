#include "metal.h"

bool Metal::scatter(
	const Ray& inRay, const HitResult& hitResult,
	Vec3& outAttenuation, Ray& outScatteredRay) const
{
	const Vec3 reflectedDir = reflect(unitVector(inRay.direction()), hitResult.normal_);
	outScatteredRay = Ray(hitResult.pos_, reflectedDir);
	outAttenuation = albedo_;
	const bool isOutwardRay = (dot(reflectedDir, hitResult.normal_) > 0.f);
	return isOutwardRay;
}
