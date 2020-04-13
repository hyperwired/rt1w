#include "metal.h"

#include "math_util.h"

Metal::Metal(const Vec3& albedo, float fuzziness)
	: albedo_(albedo)
	, fuzziness_(fuzziness < 0.f ? 0.f : fuzziness)
{
}

bool Metal::scatter(
	const Ray& inRay, const HitResult& hitResult,
	Vec3& outAttenuation, Ray& outScatteredRay) const
{
	const Vec3 reflectedDir = reflect(unitVector(inRay.direction()), hitResult.normal_);
	outScatteredRay = Ray(hitResult.pos_, reflectedDir + (fuzziness_ * randomVecInUnitSphere()));
	outAttenuation = albedo_;
	const bool isOutwardRay = (dot(reflectedDir, hitResult.normal_) > 0.f);
	return isOutwardRay;
}
