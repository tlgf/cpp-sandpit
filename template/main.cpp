#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>

template <typename LMAO> LMAO my_adder(LMAO a, LMAO b, LMAO c) {
  return a + b + c;
}

int main(int argc, char *argv[]) {

  auto x = std::make_unique<std::vector<int>>(
      std::initializer_list<int>{1, 2, 3, 7, 9});
  std::cout << my_adder(5, 6, 7) << std::endl;

  return EXIT_SUCCESS;
}
