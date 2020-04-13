#pragma once

#include <iostream>

class Vec3 {
public:

	Vec3() : e{ 0.f, 0.f, 0.f } {}
	Vec3(float e0, float e1, float e2);

	float x() const { return e[0]; }
	float y() const { return e[1]; }
	float z() const { return e[2]; }

	Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
	float operator[](int i) const { return e[i]; }
	float& operator[](int i) { return e[i]; }

	Vec3& operator+=(const Vec3& v);

	Vec3& operator*=(const float t);

	Vec3& operator/=(const float t);

	float length() const;

	float lengthSq() const;

	void writeColor(std::ostream& out, int samplesPerPixel) const;

public:
	float e[3];

public:
	static const Vec3 ZeroVec;	// (0,0,0)
	static const Vec3 OneVec;	// (1,1,1)
};

inline std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vec3 operator+(const Vec3& u, const Vec3& v)
{
	return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Vec3 operator-(const Vec3& u, const Vec3& v)
{
	return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline Vec3 operator*(const Vec3& u, const Vec3& v)
{
	return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Vec3 operator*(float t, const Vec3& v)
{
	return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vec3 operator*(const Vec3& v, float t)
{
	return t * v;
}

inline Vec3 operator/(Vec3 v, float t) {
	return (1 / t) * v;
}

inline float dot(const Vec3& u, const Vec3& v)
{
	const float dp = 
		( u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2]);	
	return dp;
}

inline Vec3 cross(const Vec3& u, const Vec3& v)
{
	const Vec3 cp = 
		Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
			 u.e[2] * v.e[0] - u.e[0] * v.e[2],
			 u.e[0] * v.e[1] - u.e[1] * v.e[0]);
	return cp;
}

inline Vec3 unitVector(Vec3 v)
{
	const Vec3 uv = (v / v.length());
	return uv;
}


