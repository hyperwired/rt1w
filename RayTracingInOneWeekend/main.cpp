#include <iostream>

#include "math_util.h"
#include "ray.h"
#include "vec3.h"

float sphereHitRayParam(const Vec3& center, float radius, const Ray& r)
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
	const Vec3 origToSphereCenter = r.origin() - center;
	const float a = dot(r.direction(), r.direction());
	const float half_b = dot(origToSphereCenter, r.direction());
	const float c = dot(origToSphereCenter, origToSphereCenter) - (radius * radius);
	const float discriminant = (half_b * half_b) - (a * c);
	if (discriminant <= 0.f)
	{
		// not a hit
		return -1.0f;
	}
	else
	{
		// return the first of two roots (value for ray param t) 
		// that is an intersection with the sphere surface
		const float t = (-half_b - sqrt(discriminant)) / (2.0f * a);
		return t;
	}
}

Vec3 rayColor(const Ray& r)
{
	const Vec3 sphereCenter(0.f, 0.f, -1.0f);
	const float sphereRadius = 0.5f;
	const float rayParamT = sphereHitRayParam(sphereCenter, sphereRadius, r);
	if (rayParamT >= 0.f)
	{
		// Determine where the ray hit, and the sphere normal
		const Vec3 intersectionPos = r.at(rayParamT);
		const Vec3 sphereNormal = unitVector(intersectionPos - sphereCenter);
		const Vec3 normalColor = 0.5f * (Vec3(1.0f, 1.0f, 1.0f) + sphereNormal);
		return normalColor;
	}
	const Vec3 unitDir = unitVector(r.direction());

	// lerp from white -> blue based on ray direction y
	const float yDirNorm = (0.5f * unitDir.y() + 1.0f);
	return lerp(yDirNorm, Vec3(1.0f, 1.0f, 1.0f), Vec3(0.5f, 0.7f, 1.0f));
}

int main()
{
	const int imageWidth = 200;
	const int imageHeight = 100;

	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	const Vec3 lowerLeftCorner(-2.0f, -1.0f, -1.0f);
	const Vec3 xOffset(4.0f, 0.0f, 0.0f);
	const Vec3 yOffset(0.0f, 2.0f, 0.0f);
	const Vec3 origin(0.0f, 0.0f, 0.0f);

	for (int j = imageHeight - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < imageWidth; ++i)
		{
			const float u = static_cast<float>(i) / imageWidth;
			const float v = static_cast<float>(j) / imageHeight;
			const Vec3 direction = lowerLeftCorner + u * xOffset + v * yOffset;
			const Ray r(origin, direction);
			const Vec3 color = rayColor(r);
			color.writeColor(std::cout);
		}
	}

	return 0;
}