#include <iostream>
#include <decoder.hpp>

#include "CLI/CLI.hpp"

int main(int argc, char** argv) {
  CLI::App app{"Simple C++ JWT tool."};
  app.require_option();

  std::string token{};
  app.add_option("token", token, "JWT token to decode")->required(true);

  CLI11_PARSE(app, argc, argv);

  if (std::count(token.begin(), token.end(), '.') != 2) {
    std::cerr << "Invalid JWT token" << std::endl;
    return EXIT_FAILURE;
  }

  const auto start = token.find('.') + 1;
  const auto end = token.find('.', start);

  std::cout << simple_cpp::base64::decode(token.substr(start, end - start));
  std::cout << std::endl;
  return EXIT_SUCCESS;
}