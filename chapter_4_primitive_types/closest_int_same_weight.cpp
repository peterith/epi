#include <iostream>
#include <limits>

// n = number of input bits

// time: O(n), space: O(1)
// flip two rightmost consecutive bits that differ
unsigned long closest_int_same_weight_1(unsigned long x) {
  for (int i = 0; i < 63; ++i) {
    if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) {
      x ^= (1UL << i) | (1UL << (i + 1));
      return x;
    }
  }
  throw std::invalid_argument("all bits are 0s or 1s");
}

// time: O(1), space: O(1)
// use bits manupulation tricks to find first rightmost bit that differ
unsigned long closest_int_same_weight_2(unsigned long x) {
  unsigned long lowest_set_bit = x & ~(x - 1);
  unsigned long lowest_unset_bit = ~x & (x + 1);
  if (lowest_set_bit == 0 || lowest_unset_bit == 0) {
    throw std::invalid_argument("all bits are 0s or 1s");
  }
  if (lowest_set_bit > lowest_unset_bit) {
    return x ^ (lowest_set_bit | (lowest_set_bit >> 1));
  }
  return x ^ (lowest_unset_bit | (lowest_unset_bit >> 1));
}

int main() {
  unsigned long ul_max = std::numeric_limits<unsigned long>::max();

  std::cout << "closest_int_same_weight_1" << std::endl;
  std::cout << closest_int_same_weight_1(0) << std::endl;      // throw exception
  std::cout << closest_int_same_weight_1(ul_max) << std::endl; // throw exception
  std::cout << closest_int_same_weight_1(5) << std::endl;      // 6
  std::cout << closest_int_same_weight_1(7) << std::endl;      // 11
  std::cout << closest_int_same_weight_1(10) << std::endl;     // 9

  std::cout << "closest_int_same_weight_2" << std::endl;
  std::cout << closest_int_same_weight_2(0) << std::endl;      // throw exception
  std::cout << closest_int_same_weight_2(ul_max) << std::endl; // throw exception
  std::cout << closest_int_same_weight_2(5) << std::endl;      // 6
  std::cout << closest_int_same_weight_2(7) << std::endl;      // 11
  std::cout << closest_int_same_weight_2(10) << std::endl;     // 9

  return 0;
}