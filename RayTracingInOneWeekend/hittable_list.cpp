#include "hittable_list.h"

HittableList::HittableList(const std::shared_ptr<Hittable>& object)
{
	add(object);
}

void HittableList::clear()
{
	objects_.clear();
}

void HittableList::add(const std::shared_ptr<Hittable>& object)
{
	objects_.emplace_back(object);
}

bool HittableList::hit(const Ray& r, float t_min, float t_max, HitResult& hitResult) const
{
	HitResult tempResult = {};
	bool hasHit = false;
	float closest_t = t_max;

	// iterate through objects, storing the closest hit so far
	for (const auto& object : objects_)
	{
		if (object->hit(r, t_min, closest_t, tempResult))
		{
			hasHit = true;
			closest_t = tempResult.t_;
			hitResult = tempResult;
		}
	}

	return hasHit;
}
