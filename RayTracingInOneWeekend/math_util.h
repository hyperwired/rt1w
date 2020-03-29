#pragma once

#include <limits>

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
	return (t > 1.0f) ? 1.0f : ((t < 0.f) ? 0.f : t);
}

template <class T>
T lerp(float t, const T& a, const T& b)
{
	t = saturate(t);
	return ((1.0f - t) * a) + (t * b);
}

