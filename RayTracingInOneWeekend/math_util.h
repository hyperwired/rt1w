#pragma once

#include "vec3.h"

#include <cstdlib>
#include <functional>
#include <limits>
#include <random>

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385f;

inline float degrees_to_radians(float degrees) {
	return degrees * pi / 180;
}

inline float clamp(float t, float minval, float maxval)
{
	return (t > maxval) ? maxval : ((t < minval) ? minval : t);
}

inline float saturate(float t)
{
	return clamp(t, 0.f, 1.0f);
}

inline float saturateExc(float t)
{
	return clamp(t, 0.f, 0.9999f);
}


template <class T>
T lerp(float t, const T& a, const T& b)
{
	t = saturate(t);
	return ((1.0f - t) * a) + (t * b);
}

#define OLD_STYLE_RAND 0
#if OLD_STYLE_RAND
// return real in [0, 1)
inline float randomFloat()
{
	return rand() / (RAND_MAX + 1.0);
}
#else
// return real in [0, 1)
inline float randomFloat()
{
	static std::uniform_real_distribution<float> distribution(0.f, 1.f);
	static std::mt19937 generator;
	static std::function<float()> rand_generator = std::bind(distribution, generator);
	return rand_generator();
}
#endif

// return real in [min, max)
inline float randomFloatRange(float min, float max)
{
	return min + (max - min) * randomFloat();
}

inline Vec3 randomVecInUnitSphere()
{
	Vec3 randVec = Vec3::ZeroVec;
	while (true)
	{
		randVec = Vec3::random(-1.f, 1.f);
		if (randVec.lengthSq() >= 1.f)
		{
			// reject points outside of unit sphere
			continue;
		}
		return randVec;
	}
}

inline Vec3 randomUnitVectorSphereSurface()
{
	const float a = randomFloatRange(0.f, 2.f * pi);
	const float z = randomFloatRange(-1.f, 1.f);
	const float r = sqrt(1 - z * z);
	return Vec3(r * cosf(a), r * sinf(a), z);
}

