#include <iostream>

// n = number of input digits

// time: O(n), space: O(1)
// use mod and division
int reverse(int x) {
  int result = 0;
  while (x) {
    result = (result * 10) + (x % 10);
    x /= 10;
  }
  return result;
}

int main() {
  std::cout << reverse(0) << std::endl;      // 0
  std::cout << reverse(300) << std::endl;    // 3
  std::cout << reverse(13024) << std::endl;  // 42031
  std::cout << reverse(-13024) << std::endl; // -42031
  std::cout << reverse(999) << std::endl;    // 999
}