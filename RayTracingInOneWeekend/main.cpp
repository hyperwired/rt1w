#include <cstdio>
#include <iostream>

int main()
{
	const int imageWidth = 200;
	const int imageHeight = 100;

	printf("P3\n%d %d\n255\n", imageWidth, imageHeight);
	for (int j = imageHeight - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < imageWidth; ++i)
		{
			const double r = static_cast<double>(i) / imageWidth;
			const double g = static_cast<double>(j) / imageHeight;
			const double b = 0.2;
			const int ir = static_cast<int>(255.999 * r);
			const int ig = static_cast<int>(255.999 * g);
			const int ib = static_cast<int>(255.999 * b);
			printf("%d %d %d\n", ir, ig, ib);
		}
	}

	return 0;
}