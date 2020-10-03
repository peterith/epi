#include <cmath>
#include <iostream>

// n = number of input digits

// time: O(n), space: O(1)
// check and remove msd and lsd
bool is_palindrone_number(int x) {
  if (x < 0) {
    return false;
  }
  int digits = std::log10(x) + 1;
  int msd = std::pow(10, digits - 1);
  for (int i = 0; i < (digits / 2); ++i) {
    if ((x % 10) != ((x / msd) % 10)) {
      return false;
    }
    x %= msd;
    x /= 10;
    msd /= 100;
  }
  return true;
}

int main() {
  std::cout << is_palindrone_number(-101) << std::endl; // 0
  std::cout << is_palindrone_number(0) << std::endl;    // 1
  std::cout << is_palindrone_number(101) << std::endl;  // 1
  std::cout << is_palindrone_number(105) << std::endl;  // 0
  std::cout << is_palindrone_number(999) << std::endl;  // 1
}