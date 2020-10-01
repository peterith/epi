#include <iostream>

// time: O(n), space: O(1)
// iterate and flip result if bit is 1
int parity_1(unsigned long x) {
  int result = 0;
  while (x) {
    result ^= x & 1;
    x >>= 1;
  }
  return result;
}

// time: O(n), space: O(1)
// use bit manipulation trick to shorten iteration
int parity_2(unsigned long x) {
  int result = 0;
  while (x) {
    result ^= 1;
    x &= x - 1;
  }
  return result;
}

// time: O(n/L), space: O(L^2)
// use lookup table
int parity_3(unsigned long x) {
  int result = 0;
  unsigned cache[] = {0, 1, 1, 0};
  while (x) {
    result ^= cache[x & 0b11];
    x >>= 2;
  }
  return result;
}

// time: O(log(n)), space: O(1)
// use XOR associativity
int parity_4(unsigned long x) {
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 1;
}

int main() {
  std::cout << parity_1(0) << std::endl;  // 0
  std::cout << parity_1(1) << std::endl;  // 1
  std::cout << parity_1(5) << std::endl;  // 0
  std::cout << parity_1(11) << std::endl; // 1

  std::cout << parity_2(0) << std::endl;  // 0
  std::cout << parity_2(1) << std::endl;  // 1
  std::cout << parity_2(5) << std::endl;  // 0
  std::cout << parity_2(11) << std::endl; // 1

  std::cout << parity_3(0) << std::endl;  // 0
  std::cout << parity_3(1) << std::endl;  // 1
  std::cout << parity_3(5) << std::endl;  // 0
  std::cout << parity_3(11) << std::endl; // 1

  std::cout << parity_4(0) << std::endl;  // 0
  std::cout << parity_4(1) << std::endl;  // 1
  std::cout << parity_4(5) << std::endl;  // 0
  std::cout << parity_4(11) << std::endl; // 1
}