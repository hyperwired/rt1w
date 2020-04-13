#pragma once

#include "ray.h"
#include "vec3.h"

struct Viewport
{
	Viewport() = default;
	Viewport(float width, float height) : width_(width), height_(height) {}

	float width_ = 200;
	float height_ = 100;
};


class Camera
{
public:
	Camera(const Viewport& viewport, const float viewportPixelDensity = 1.0f);

	Ray getRay(float u, float v);

public:
	Vec3 lowerLeftCorner_ = Vec3(-2.0f, -1.0f, -1.0f);
	Vec3 xOffset_ = Vec3(4.0f, 0.0f, 0.0f);
	Vec3 yOffset_ = Vec3(0.0f, 2.0f, 0.0f);
	Vec3 origin_ = Vec3(0.0f, 0.0f, 0.0f);

protected:
	float aspectRatio_ = 1.0f;
};
