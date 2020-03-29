#pragma once

#include <iostream>

class vec3 {
public:

	vec3() : e{ 0.f, 0.f, 0.f } {}
	vec3(float e0, float e1, float e2) : e{ e0, e1, e2 } {}

	float x() const { return e[0]; }
	float y() const { return e[1]; }
	float z() const { return e[2]; }

	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	float operator[](int i) const { return e[i]; }
	float& operator[](int i) { return e[i]; }

	vec3& operator+=(const vec3& v);

	vec3& operator*=(const float t);

	vec3& operator/=(const float t);

	float length() const;

	float lengthSq() const;

	void writeColor(std::ostream& out) const;

public:
	float e[3];
};

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(float t, const vec3& v) {
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, float t) {
	return t * v;
}

inline vec3 operator/(vec3 v, float t) {
	return (1 / t) * v;
}

inline float dot(const vec3& u, const vec3& v) {
	const float dp = 
		( u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2]);	
	return dp;
}

inline vec3 cross(const vec3& u, const vec3& v) {
	const vec3 cp = 
		vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
			 u.e[2] * v.e[0] - u.e[0] * v.e[2],
			 u.e[0] * v.e[1] - u.e[1] * v.e[0]);
	return cp;
}

inline vec3 unitVector(vec3 v) {
	const vec3 uv = (v / v.length());
	return uv;
}