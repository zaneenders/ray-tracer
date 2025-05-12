#include <iostream>

int hello() { return 69; }

[[nodiscard]]
int entry(int size) {
  int image_width = size;
  int image_height = size;
  std::cout << "P3\n"
            << image_width << ' ' << image_height << "\n"
            << (size - 1) << "\n";
  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines Remaining: " << (image_height - 1) << ' '
              << std::flush;
    for (int i = 0; i < image_width; i++) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);
      auto b = 0.0;

      int ir = int(255.999 * r);
      int ig = int(255.999 * g);
      int ib = int(255.999 * b);
      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
  std::clog << "\rDone.                                   \n";

  return 0;
}