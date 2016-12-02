#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <map>

int main() {
  std::string tok;
  int dir = 0;
  /* 0 - Up
   * 1 - Right
   * 2 - Down
   * 3 - Left
   */

  int x = 0, y = 0;

  char direction;
  int amount;

  while (std::cin >> tok) {
    std::stringstream ss(tok);

    ss >> direction >> amount;

    if (direction == 'R') dir = (dir + 1) % 4;
    else dir = (dir - 1 + 4) % 4;

    switch (dir) {
      case 0:
        y += amount;
        break;
      case 1:
        x += amount;
        break;
      case 2:
        y -= amount;
        break;
      case 3:
        x -= amount;
        break;
    }
  }

  if (x < 0) x *= -1;
  if (y < 0) y *= -1;

  std::cout << x + y << std::endl;

  return 0;
}
