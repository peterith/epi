#include <iostream>

// time: O(1), space: O(1)
bool is_power_of_two(unsigned long x) { return x ? !(x & (x - 1)) : 0; }

int main() {
  std::cout << is_power_of_two(0) << std::endl;   // 0
  std::cout << is_power_of_two(1) << std::endl;   // 1
  std::cout << is_power_of_two(2) << std::endl;   // 1
  std::cout << is_power_of_two(64) << std::endl;  // 1
  std::cout << is_power_of_two(100) << std::endl; // 0
}