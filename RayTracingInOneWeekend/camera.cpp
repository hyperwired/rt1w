#include "camera.h"

Ray Camera::getRay(float u, float v)
{
	return Ray(origin_, lowerLeftCorner_ + (u * xOffset_) + (v * yOffset_) - origin_);
}
