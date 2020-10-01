#include <iostream>

// time: O(1), space: O(1)
// flip bits if they are different
unsigned long swap_bits(unsigned long x, int i, int j) {
  if (((x >> i) & 1) != ((x >> j) & 1)) {
    x ^= (1UL << i) | (1UL << j);
  }
  return x;
}

int main() {
  std::cout << swap_bits(0, 0, 10) << std::endl; // 0
  std::cout << swap_bits(1, 0, 2) << std::endl;  // 4
  std::cout << swap_bits(2, 0, 1) << std::endl;  // 1
  std::cout << swap_bits(5, 0, 1) << std::endl;  // 6
  return 0;
}