#include "entry.h"
#include "camera.h"
#include "hittable_list.h"
#include "interval.h"
#include "sphere.h"
#include "vec3.h"

int hello() { return 69; }

void entry(int width) {
  hittable_list world;

  world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0)); // earth
  world.add(make_shared<sphere>(point3(0.0, 0.0, -1.2), 0.4));      // center
  world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5));     // left
  world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.6));      // right

  camera cam;

  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = width;

  cam.render(world);
}