#include "Application.hpp"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {
  Application app{};
    std::cout<<"Start app\n";
  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}