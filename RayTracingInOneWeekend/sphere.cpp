#include "sphere.h"

bool Sphere::hit(const Ray& r, float t_min, float t_max, HitResult& hitResult) const
{
	/*
	1) sphere eq:	(x - c_x)^2 + (y - c_y)^2 + (z - c_z)^2 = R^2
					(p - c).(p - c) = R^2
					// as dot product where p and c are vectors
	2) ray eq:		p(t) = a + tb
					// a and b are vectors: a is ray origin, b is ray dir
	3) 2 into 1:	(p(t) - c).(p(t) - c) = R^2
					(a + tb - c).(a + tb - c) = R^2
					tb.tb + tb.(a - c) + tb.(a - c) + (a - c).(a - c) - R^2 = 0
					t^2b.b + 2tb.(a - c) + (a - c).(a - c) - R^2 = 0
					// note Quadratic form: x^2.A + x.B + C = 0  (where t = x)
	5) Quadratic discriminant: B^2 - 4AC
		> 0 : 2 real roots	(intersects i.e. crosses into and outside of)
		= 0 : 1 real roots	(tangential to edge)
		< 0 : 0 real roots	(does not intersect)
	6) Quadratic formula:	(-B +/- sqrt(B^2 - 4AC)) / 2A
	7) Half-B variant:		((-2H) +/- sqrt((2H)^2- 4AC)) / 2A
							(-2H +/- (2 * sqrt(H^2 - AC))) / 2A
							(-H +/- sqrt(H^2-4AC)) / A
	8) Half-B discriminant:	H^2 - AC
	*/
	const Vec3 origToSphereCenter = r.origin() - center_;
	const float a = dot(r.direction(), r.direction());
	const float half_b = dot(origToSphereCenter, r.direction());
	const float c = dot(origToSphereCenter, origToSphereCenter) - (radius_ * radius_);
	const float discriminant = (half_b * half_b) - (a * c);

	if (discriminant > 0.f)
	{
		const float root = sqrt(discriminant);

		// The first of two roots (value for ray param t) 
		// that is an intersection with the sphere surface
		float t = (-half_b - root) / a;
		if (t < t_max && t > t_min)
		{
			hitResult = makeHitResult(r, t);
			return true;
		}

		// The second of two roots
		t = (-half_b + root) / a;
		if (t < t_max && t > t_min)
		{
			hitResult = makeHitResult(r, t);
			return true;
		}
	}

	return false;
}

HitResult Sphere::makeHitResult(const Ray& r, float t) const
{
	HitResult res = {};
	res.t_ = t;
	res.pos_ = r.at(t);
	const Vec3 outwardNormal = (res.pos_ - center_) / radius_;
	res.setFaceNormal(r, outwardNormal);
	return res;
}
