#include <iostream>
#include <vector>

int main() {
  int pos = 5;
  std::string line{};

  while (std::getline(std::cin, line)) {
    for (auto ch = line.begin(); ch != line.end(); ++ch) {
      switch (*ch) {
        case 'U':
          if (pos > 3) pos -= 3;
          break;
        case 'R':
          if (pos % 3 != 0) pos += 1;
          break;
        case 'D':
          if (pos < 7) pos += 3;
          break;
        case 'L':
          if ((pos - 1) % 3 != 0) pos -= 1;
          break;
      }
    }

    std::cout << pos;
  }
  std::cout << std::endl;

  return 0;
}
