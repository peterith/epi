#include <iostream>

// n = number of input bits

// time: O(n), space: O(1)
// result is (x^(y/2)^2 if y is even and result is x(x^(y/2)^2 if y is odd
double power(double x, int y) {
  if (y < 0) {
    x = 1.0 / x;
    y = -y;
  }
  double result = 1.0;
  while (y) {
    if (y & 1) {
      result *= x;
    }
    x *= x;
    y >>= 1;
  }
  return result;
}

int main() {
  std::cout << power(0, 0) << std::endl;   // 1
  std::cout << power(0, 5) << std::endl;   // 0
  std::cout << power(5, 2) << std::endl;   // 25
  std::cout << power(1.1, 3) << std::endl; // 1.331
  std::cout << power(5, -2) << std::endl;  // 0.04
}