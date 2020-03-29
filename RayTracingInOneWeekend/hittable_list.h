#pragma once

#include "hittable.h"

#include <memory>
#include <vector>

class HittableList : public Hittable
{
public:
	HittableList() = default;
	HittableList(const std::shared_ptr<Hittable>& object);

	void clear();
	void add(const std::shared_ptr<Hittable>& object);

	virtual bool hit(const Ray& r, float t_min, float t_max, HitResult& hitResult) const override;
public:
	std::vector<std::shared_ptr<Hittable>> objects_;

};

