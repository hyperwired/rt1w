#include "camera.h"
#include <cassert>

Camera::Camera(const Viewport& viewport, const float viewportPixelDensity /*= 1.0f*/)
{
	assert(viewport.width > 0 && viewport.height > 0 && viewportPixelDensity > 0.f);
	const float aspectRatio = viewport.width_ / viewport.height_;
	const float offsetBase = 2.0f / viewportPixelDensity;
	lowerLeftCorner_ = Vec3(-aspectRatio, -1.0f, -1.0f);
	xOffset_ = Vec3(offsetBase * aspectRatio, 0.0f, 0.0f);
	yOffset_ = Vec3(0.0f, offsetBase, 0.0f);
}

Ray Camera::getRay(float u, float v)
{
	return Ray(origin_, lowerLeftCorner_ + (u * xOffset_) + (v * yOffset_) - origin_);
}
