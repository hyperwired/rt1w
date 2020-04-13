#include "vec3.h"

#include "math_util.h"

const Vec3 Vec3::ZeroVec(1.0f, 1.0f, 1.0f);
const Vec3 Vec3::OneVec(1.0f, 1.0f, 1.0f);


Vec3::Vec3(float e0, float e1, float e2)
	: e{ e0, e1, e2 }
{

}

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
	return (e[0] * e[0] + 
			e[1] * e[1] + 
			e[2] * e[2]);
}

void Vec3::writeColor(std::ostream& out, int samplesPerPixel) const
{
	// divide by number of samples
	const float sampleScale = 1.f / samplesPerPixel;
	
	// sqrt: since gamma approximation of gamma = 2, and gamma corrected val is val ^ (1/gamma)
	const float r = sqrt(sampleScale * e[0]);
	const float g = sqrt(sampleScale * e[1]);
	const float b = sqrt(sampleScale * e[2]);

	// 1 past maximum output value
	const float postScale = 256.f;

	// Write the translated [0,255] value of each color component.
	out << static_cast<int>(postScale * saturateExc(r)) << ' '
		<< static_cast<int>(postScale * saturateExc(g)) << ' '
		<< static_cast<int>(postScale * saturateExc(b)) << '\n';
}


Vec3 Vec3::random()
{
	return Vec3(randomFloat(), randomFloat(), randomFloat());
}

Vec3 Vec3::random(float min, float max)
{
	return Vec3(randomFloatRange(min, max),
				randomFloatRange(min, max),
				randomFloatRange(min, max));
}
