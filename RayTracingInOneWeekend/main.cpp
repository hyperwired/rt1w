#include <iostream>

#include "math_util.h"

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"
#include "ray.h"
#include "vec3.h"


Vec3 rayColor(const Ray& r, const Hittable& world)
{
	HitResult hitResult = {};
	if (world.hit(r, 0, infinity, hitResult))
	{
		const Vec3 normalColor = 0.5f * (Vec3::OneVec + hitResult.normal_);
		return normalColor;
	}

	// not hit: lerp from white -> blue based on ray direction y
	const Vec3 unitDir = unitVector(r.direction());
	const float yDirNorm = (0.5f * unitDir.y() + 1.0f);
	return lerp(yDirNorm, Vec3(1.0f, 1.0f, 1.0f), Vec3(0.5f, 0.7f, 1.0f));
}

int main()
{
	const int imageWidthBase = 200;
	const int imageHeightBase = 100;
	const int pixelMultiplier = 3;
	const int imageWidth = imageWidthBase * pixelMultiplier;
	const int imageHeight = imageHeightBase * pixelMultiplier;
	const int samplesPerPixel = 100;

	Viewport viewport(imageWidth, imageHeight);
	Camera cam(viewport);

	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	const Vec3 lowerLeftCorner(-2.0f, -1.0f, -1.0f);
	const Vec3 xOffset(4.0f, 0.0f, 0.0f);
	const Vec3 yOffset(0.0f, 2.0f, 0.0f);
	const Vec3 origin(0.0f, 0.0f, 0.0f);

	HittableList world;
	world.add(std::make_shared<Sphere>(Vec3(0.f, 0.f, -1.f), 0.5f));
	world.add(std::make_shared<Sphere>(Vec3(0.f, -100.5f, -1.f), 100.f));
	
	for (int j = imageHeight - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < imageWidth; ++i)
		{
			Vec3 color = Vec3::ZeroVec;
			for (int s = 0; s < samplesPerPixel; ++s)
			{
				const float u = static_cast<float>(i + randomFloat()) / imageWidth;
				const float v = static_cast<float>(j + randomFloat()) / imageHeight;
				const Ray r = cam.getRay(u, v);
				color += rayColor(r, world);
			}
			
			color.writeColor(std::cout, samplesPerPixel);
		}
	}

	std::cerr << "\nDone.\n";

	return 0;
}