#pragma once

#include "ray.h"
#include "vec3.h"

class Camera
{
public:
	Camera() = default;

	Ray getRay(float u, float v);

public:
	Vec3 lowerLeftCorner_ = Vec3(-2.0f, -1.0f, -1.0f);
	Vec3 xOffset_ = Vec3(4.0f, 0.0f, 0.0f);
	Vec3 yOffset_ = Vec3(0.0f, 2.0f, 0.0f);
	Vec3 origin_ = Vec3(0.0f, 0.0f, 0.0f);
};
