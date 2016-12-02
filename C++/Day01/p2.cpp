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

  std::map<std::pair<int, int>, bool> seen;

  seen[std::make_pair(0, 0)] = true;

  while (std::cin >> tok) {
    std::stringstream ss(tok);

    ss >> direction >> amount;

    if (direction == 'R') dir = (dir + 1) % 4;
    else dir = (dir - 1 + 4) % 4;

    std::pair<int, int> delta;

    switch (dir) {
      case 0:
        delta = std::make_pair(0, amount);
        break;
      case 1:
        delta = std::make_pair(amount, 0);
        break;
      case 2:
        delta = std::make_pair(0, -amount);
        break;
      case 3:
        delta = std::make_pair(-amount, 0);
        break;
    }

    while (delta.first != 0 || delta.second != 0) {
      if (delta.first > 0) {
        ++x;
        delta.first--;
      } else if (delta.first < 0) {
        --x;
        delta.first++;
      }
      if (delta.second > 0) {
        ++y;
        delta.second--;
      } else if (delta.second < 0) {
        --y;
        delta.second++;
      }

      auto pos = std::make_pair(x, y);
      if (seen.find(pos) != seen.end()) {
        if (x < 0) x *= -1;
        if (y < 0) y *= -1;

        std::cout << x + y << std::endl;

        goto done;
      }
      seen[pos] = true;
    }
  }

done:
  return 0;

}
