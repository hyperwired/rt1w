#pragma once

#include "ray.h"
#include "vec3.h"

#include <memory>

class Material;

struct HitResult
{
	Vec3 pos_ = {};
	Vec3 normal_ = {};
	std::shared_ptr<Material> material_;
	float t_ = -1.0f;
	bool frontFacing_ = true;

	void setFaceNormal(const Ray& r, const Vec3& outwardNormal);
};

class Hittable
{
public:
	virtual bool hit(const Ray& r, float t_min, float t_max, HitResult& hitResult) const = 0;

	void setMaterial(std::shared_ptr<Material> material) { material_ = material; }
	std::shared_ptr<Material> getMaterial() { return material_; }
	
public:
	std::shared_ptr<Material> material_;
};

