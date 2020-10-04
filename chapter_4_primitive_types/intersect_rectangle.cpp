#include <iostream>

struct Rect {
  int x;
  int y;
  int width;
  int height;
};

// time: O(1), space: O(1)
Rect intersect_rectangle(const Rect &r1, const Rect &r2) {
  if (r1.width < 0 || r1.height < 0 || r1.width < 0 || r1.height < 0) {
    throw std::invalid_argument("width and height cannot be negative");
  }
  if ((r1.x > (r2.x + r2.width)) || (r2.x > (r1.x + r1.width)) || (r1.y > (r2.y + r2.height)) ||
      (r2.y > (r1.y + r1.height))) {
    return {0, 0, -1, -1};
  }
  return {std::max(r1.x, r2.x), std::max(r2.y, r2.y),
          std::min(r1.x + r1.width, r2.x + r2.width) - std::max(r1.x, r2.x),
          std::min(r1.y + r1.height, r2.y + r2.height) - std::max(r1.y, r2.y)};
}

int main() {
  Rect r1 = intersect_rectangle({1, 1, -1, -1}, {2, 2, -1, -1}); // throw error
  Rect r2 = intersect_rectangle({1, 1, 1, 1}, {5, 5, 1, 1});     // {0, 0, -1, -1}
  std::cout << r2.x << ' ' << r2.y << ' ' << r2.width << ' ' << r2.height << std::endl;
  Rect r3 = intersect_rectangle({1, 1, 1, 1}, {2, 2, 1, 1}); // {2, 2, 0, 0}
  std::cout << r3.x << ' ' << r3.y << ' ' << r3.width << ' ' << r3.height << std::endl;
  Rect r4 = intersect_rectangle({-1, -3, 6, 10}, {2, 2, 3, 2}); // {2, 2, 3, 2}
  std::cout << r4.x << ' ' << r4.y << ' ' << r4.width << ' ' << r4.height << std::endl;
  Rect r5 = intersect_rectangle({2, 3, 4, 4}, {4, 6, 10, 8}); // {4, 6, 2, 1}
  std::cout << r5.x << ' ' << r5.y << ' ' << r5.width << ' ' << r5.height << std::endl;
}