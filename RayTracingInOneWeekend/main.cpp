#include <iostream>

#include "vec3.h"

int main()
{
	const int imageWidth = 200;
	const int imageHeight = 100;

	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";
	for (int j = imageHeight - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < imageWidth; ++i)
		{
			const Vec3 color(
				static_cast<float>(i) / imageWidth,
				static_cast<float>(j) / imageHeight,
				0.2f);
			color.writeColor(std::cout);
		}
	}

	return 0;
}