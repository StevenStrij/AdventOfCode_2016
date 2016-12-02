#include <iostream>

/*
    1
  2 3 4
5 6 7 8 9
  A B C
    D
 */

bool isValid(std::string* map, int x, int y) {
  return (x >= 0 && x < 5) &&
         (y >= 0 && y < 5) &&
         (map[y][x] != '.');
}

int main() {
  int x = 0, y = 2;
  std::string map[] = {
    {"..1.."},
    {".234."},
    {"56789"},
    {".ABC."},
    {"..D.."}
  };
  std::string line{};

  while (std::getline(std::cin, line)) {
    for (auto ch = line.begin(); ch != line.end(); ++ch) {
      switch (*ch) {
        case 'U':
          if (isValid(map, x, y - 1)) y -= 1;
          break;
        case 'R':
          if (isValid(map, x + 1, y)) x += 1;
          break;
        case 'D':
          if (isValid(map, x, y + 1)) y += 1;
          break;
        case 'L':
          if (isValid(map, x - 1, y)) x -= 1;
          break;
      }
    }
    std::cout << map[y][x] << std::endl;

  }
  std::cout << std::endl;

  return 0;
}
