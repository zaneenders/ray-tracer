#include "entry.h"
#include "color.h"
#include "hittable.h"
#include "hittable_list.h"
#include "interval.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"
#include <iostream>

int hello() { return 69; }

double hit_sphere(const point3 &center, double radius, const ray &r) {
  vec3 oc = center - r.origin();
  auto a = dot(r.direction(), r.direction());
  auto b = -2.0 * dot(r.direction(), oc);
  auto c = dot(oc, oc) - radius * radius;
  auto discriminant = b * b - 4 * a * c;
  if (discriminant < 0) {
    return -1.0;
  } else {
    return (-b - std::sqrt(discriminant)) / (2.0 * a);
  }
}

const color white_color = color(1.0, 1.0, 1.0);
const color blue_color = color(0.5, 0.7, 1.0);
const color red_color = color(1.0, 0.0, 0.0);
const color green_color = color(72.0 / 255.0, 1.0, 0.0);

color ray_color(const ray &r, const hittable &world) {
  hit_record rec;
  if (world.hit(r, interval(0, infinity), rec)) {
    return 0.5 * (rec.normal + color(1, 1, 1));
  }

  vec3 unit_direction = unit_vector(r.direction());
  auto a = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

void entry(int width) {
  auto aspect_ratio = 16.0 / 9.0;
  int image_width = width;

  // Calculate the image height, and ensure that it's at least 1.
  int image_height = int(image_width / aspect_ratio);
  image_height = (image_height < 1) ? 1 : image_height;

  // World
  hittable_list world;

  world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
  world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

  // Camera
  auto focal_length = 1.0;
  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (double(image_width) / image_height);
  auto camera_center = point3(0, 0, 0);

  // Calculate the vectors across the horizontal and down the vertical viewport
  // edges.
  auto viewport_u = vec3(viewport_width, 0, 0);
  auto viewport_v = vec3(0, -viewport_height, 0);

  // Calculate the horizontal and vertical delta vectors from pixel to pixel.
  auto pixel_delta_u = viewport_u / image_width;
  auto pixel_delta_v = viewport_v / image_height;

  // Calculate the location of the upper left pixel.
  auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) -
                             viewport_u / 2 - viewport_v / 2;
  auto pixel00_loc =
      viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

  std::cout << "P3\n"
            << image_width << ' ' << image_height << "\n"
            << (255) << "\n"; // 255 is the max value for each color.
  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines Remaining: " << (image_height - 1) << ' '
              << std::flush;
    for (int i = 0; i < image_width; i++) {
      auto pixel_center =
          pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
      auto ray_direction = pixel_center - camera_center;
      ray r(camera_center, ray_direction);

      color pixel_color = ray_color(r, world);
      write_color(std::cout, pixel_color);
    }
  }
  std::clog << "\rDone.                                   \n";
}