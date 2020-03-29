#pragma once

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

