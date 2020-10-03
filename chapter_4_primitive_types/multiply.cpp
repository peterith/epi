#include <iostream>

// n = number of input bits

// time: O(n), space: O(1)
// XOR gate is the result of adding without carry
unsigned long add(unsigned long x, unsigned long y) {
  while (y) {
    unsigned long carry = x & y;
    x ^= y;
    y = carry << 1;
  }
  return x;
}

// time: O(n^2), space: O(1)
// use highschool multiplication method
unsigned long multiply(unsigned long x, unsigned long y) {
  unsigned long result = 0;
  while (y) {
    if (y & 1) {
      result = add(result, x);
    }
    x <<= 1;
    y >>= 1;
  }
  return result;
}

int main() {
  std::cout << multiply(0, 0) << std::endl;  // 0
  std::cout << multiply(2, 0) << std::endl;  // 0
  std::cout << multiply(0, 2) << std::endl;  // 0
  std::cout << multiply(4, 2) << std::endl;  // 8
  std::cout << multiply(5, 10) << std::endl; // 50
}