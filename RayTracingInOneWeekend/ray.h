#pragma once

#include "vec3.h"

class ray
{
	ray() = default;
	ray(const vec3& origin, const vec3& direction)
		: orig_(origin), dir_(direction)
	{}

	vec3 origin() const { return orig_; }
	vec3 direction() const { return dir_; }

	vec3 at(float t) const {
		return orig_ + (t * dir_);
	}

public:
	vec3 orig_ = {};
	vec3 dir_ = {};
};

