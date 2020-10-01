#include <iostream>
#include <limits>

// time: O(n/L), space: O(L^2)
// use lookup table
unsigned long reverse_bits(unsigned long x) {
  unsigned long result = 0;
  unsigned long cache[] = {0, 2, 1, 3};
  int maskSize = 2;
  int numberOfChunk = 64 / maskSize;
  for (int i = 0; i < numberOfChunk; ++i) {
    result |= cache[(x >> (maskSize * i)) & 0b11] << ((numberOfChunk - 1 - i) * maskSize);
  }
  return result;
}

int main() {
  unsigned long ul_max = std::numeric_limits<unsigned long>::max();
  std::cout << reverse_bits(0) << std::endl;      // 0
  std::cout << reverse_bits(12456) << std::endl;  // 1516587174517014528
  std::cout << reverse_bits(ul_max) << std::endl; // 18446744073709551615
}