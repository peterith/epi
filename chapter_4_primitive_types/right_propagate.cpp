#include <iostream>

// time: O(1), space: O(1)
unsigned long right_propagate(unsigned long x) { return x ? (x | (x - 1)) : 0; }

int main() {
  std::cout << right_propagate(0) << std::endl;  // 0
  std::cout << right_propagate(1) << std::endl;  // 1
  std::cout << right_propagate(4) << std::endl;  // 7
  std::cout << right_propagate(12) << std::endl; // 15
  std::cout << right_propagate(20) << std::endl; // 23
}