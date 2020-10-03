#include <iostream>

// n = number of input bits

// time: O(n), space: O(1)
// find highest (2^k)y that is less than x
int divide(int x, int y) {
  if (!y) {
    throw std::invalid_argument("cannot divide by 0");
  }
  int y_sign = 1;
  int x_sign = 1;
  if (y < 0) {
    y = -y;
    y_sign = -1;
  }
  if (x < 0) {
    x = -x;
    x_sign = -1;
  }
  int result = 0;
  int power = 32;
  unsigned long y_powered = static_cast<unsigned long>(y) << power;
  while (x >= y) {
    while (y_powered > x) {
      y_powered >>= 1;
      --power;
    }
    result += 1 << power;
    x -= y_powered;
  }
  return result * y_sign * x_sign;
}

int main() {
  std::cout << divide(5, 0) << std::endl;    // throw exception
  std::cout << divide(0, 10) << std::endl;   // 0
  std::cout << divide(5, 1) << std::endl;    // 5
  std::cout << divide(10, 2) << std::endl;   // 5
  std::cout << divide(15, 4) << std::endl;   // 3
  std::cout << divide(-15, -4) << std::endl; // 3
  std::cout << divide(15, -4) << std::endl;  // -3
  std::cout << divide(-15, 4) << std::endl;  // -3
}