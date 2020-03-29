#include "vec3.h"

Vec3& Vec3::operator+=(const Vec3& v)
{
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

Vec3& Vec3::operator*=(const float t)
{
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

Vec3& Vec3::operator/=(const float t)
{
	return *this *= 1 / t;
}

float Vec3::length() const
{
	return sqrt(lengthSq());
}

float Vec3::lengthSq() const
{
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

void Vec3::writeColor(std::ostream& out) const
{
	// Write the translated [0,255] value of each color component.
	out << static_cast<int>(255.999f * e[0]) << ' '
		<< static_cast<int>(255.999f * e[1]) << ' '
		<< static_cast<int>(255.999f * e[2]) << '\n';
}