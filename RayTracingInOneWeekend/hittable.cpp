#include "hittable.h"

void HitResult::setFaceNormal(const Ray& r, const Vec3& outwardNormal)
{
	frontFacing_ = (dot(r.direction, outwardNormal) < 0);
	normal_ = frontFacing_ ? outwardNormal : -outwardNormal;
}
