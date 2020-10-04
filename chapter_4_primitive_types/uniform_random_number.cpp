#include <iostream>

// n = input size

// time: O(log(n)), space: O(1)
// generate up to 2^i - 1 that is bigger than number of outcome
int uniform_random_number(int x, int y) {
  if (y < x) {
    throw std::invalid_argument("first argument must be less than second argument");
  }
  int result;
  int number_of_outcome = y - x + 1;
  do {
    result = 0;
    for (int i = 0; (1 << i) - 1 < number_of_outcome; ++i) {
      result = (result << 1) | (std::rand() & 1);
    }
  } while (result >= number_of_outcome);
  return result + x;
}

int main() {
  std::cout << uniform_random_number(4, 1) << std::endl;  // throw exception
  std::cout << uniform_random_number(1, 1) << std::endl;  // 1
  std::cout << uniform_random_number(0, 4) << std::endl;  // 4
  std::cout << uniform_random_number(4, 11) << std::endl; // 10
  std::cout << uniform_random_number(5, 20) << std::endl; // 6
}