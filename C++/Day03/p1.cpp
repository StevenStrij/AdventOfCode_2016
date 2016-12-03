
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <map>

int main() {
  std::string tok;

  int s1, s2, s3;
  int c = 0;

  while (std::getline(std::cin, tok)) {
    std::stringstream ss(tok);

    ss >> s1 >> s2 >> s3;

    if (s1 + s2 > s3 && s2 + s3 > s1 && s1 + s3 > s2) {
      ++c;
    }
  }

  std::cout << c << std::endl;

  return 0;
}
