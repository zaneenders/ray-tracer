#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:
  sphere(const point3 &center, double radius)
      : center(center), radius(std::fmax(0, radius)) {}

  bool hit(const ray &r, interval ray_t, hit_record &rec) const override {
    vec3 oc = center - r.origin();
    auto a = r.direction().dot_product();
    auto h = dot(r.direction(), oc);
    auto c = oc.dot_product() - radius * radius;

    auto discriminant = h * h - a * c;
    if (discriminant < 0)
      return false;

    auto sqrtd = std::sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (h - sqrtd) / a;
    if (root <= ray_t.min || ray_t.max <= root) {
      root = (h + sqrtd) / a;
      if (root <= ray_t.min || ray_t.max <= root)
        return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - center) / radius;
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return true;
  }

private:
  point3 center;
  double radius;
};

#endif