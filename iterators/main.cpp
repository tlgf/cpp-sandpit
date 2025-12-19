#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char *argv[]) {

  if (argc <= 1)
    return EXIT_FAILURE;

  std::vector<int> args;
  std::vector<int>::iterator it;

  for (auto i = 1; i < argc; i++) {
    int val;
    printf("user val at index %d is %s\n", i, argv[i]);
    try {
      val = std::stoi(argv[i]);
    } catch (const std::invalid_argument &e) {
      std::cout << "invalid argument: " << argv[i] << std::endl;
      std::cout << "only accepts integers." return EXIT_FAILURE;
    }
    auto pos = args.end();
    args.insert(pos, val);
  }

  for (it = args.begin(); it != args.end(); it++)
    std::cout << *it << std::endl;

  return EXIT_SUCCESS;
}
