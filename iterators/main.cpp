#include <charconv>
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>
int main(int argc, char *argv[]) {

  std::cout << __cplusplus << std::endl;
  if (argc <= 1)
    return EXIT_FAILURE;

  std::vector<int> args;
  std::vector<int>::iterator it;

  for (auto i = 1; i < argc; i++) {
    int val;
    printf("user val at index %d is %s\n", i, argv[i]);
#if 0
    try {
      val = std::stoi(argv[i]);
    } catch (const std::invalid_argument &e) {
      std::cout << "invalid argument: " << argv[i] << std::endl;
      std::cout << "only accepts integers." << std::endl;
      return EXIT_FAILURE;
    }
#endif
#if 1
    auto result = std::from_chars(argv[i], argv[i + 1], val);
    if (result.ec != std::errc()) {
      std::cout << "invalid argument: " << argv[i] << std::endl;
      std::cout << "only accepts integers." << std::endl;
      return EXIT_FAILURE;
    }
#endif

    auto pos = args.end();
    args.insert(pos, val);
  }

  for (it = args.begin(); it != args.end(); it++)
    std::cout << *it << std::endl;

  return EXIT_SUCCESS;
}
