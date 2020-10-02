#include <iostream>

// time: O(1), space: O(1)
unsigned long mod_power_of_two(unsigned long x, unsigned long m) {
  if (!m || (m & (m - 1))) {
    throw std::invalid_argument("mod is not a power of 2");
  }
  return x & (m - 1);
}

int main() {
  std::cout << mod_power_of_two(10, 0) << std::endl;  // throw exception
  std::cout << mod_power_of_two(10, 3) << std::endl;  // throw exception
  std::cout << mod_power_of_two(10, 1) << std::endl;  // 0
  std::cout << mod_power_of_two(0, 2) << std::endl;   // 0
  std::cout << mod_power_of_two(26, 8) << std::endl;  // 2
  std::cout << mod_power_of_two(40, 16) << std::endl; // 8
}