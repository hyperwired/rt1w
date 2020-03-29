#pragma once

#include "vec3.h"

class Ray
{
	Ray() = default;
	Ray(const Vec3& origin, const Vec3& direction)
		: orig_(origin), dir_(direction)
	{}

	Vec3 origin() const { return orig_; }
	Vec3 direction() const { return dir_; }

	Vec3 at(float t) const {
		return orig_ + (t * dir_);
	}

public:
	Vec3 orig_ = {};
	Vec3 dir_ = {};
};

