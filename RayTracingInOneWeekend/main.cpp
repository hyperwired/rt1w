#include <iostream>

#include "ray.h"
#include "vec3.h"

Vec3 rayColor(const Ray& r)
{
	const Vec3 unitDir = unitVector(r.direction());
	const float yDirNorm = (0.5f * unitDir.y() + 1.0f);
	return lerp(yDirNorm, Vec3(1.0f, 1.0f, 1.0f), Vec3(0.5f, 0.7f, 1.0f));
}

int main()
{
	const int imageWidth = 200;
	const int imageHeight = 100;

	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	const Vec3 lowerLeftCorner(-2.0f, -1.0f, -1.0f);
	const Vec3 xOffset(4.0f, 0.0f, 0.0f);
	const Vec3 yOffset(0.0f, 2.0f, 0.0f);
	const Vec3 origin(0.0f, 0.0f, 0.0f);

	for (int j = imageHeight - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < imageWidth; ++i)
		{
			const float u = static_cast<float>(i) / imageWidth;
			const float v = static_cast<float>(j) / imageHeight;
			const Vec3 direction = lowerLeftCorner + u * xOffset + v * yOffset;
			const Ray r(origin, direction);
			const Vec3 color = rayColor(r);
			color.writeColor(std::cout);
		}
	}

	return 0;
}