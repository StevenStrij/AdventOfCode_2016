#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

typedef std::vector<std::vector<char>> Map;

int gcd(int a, int b) {
  for (int i = b; i >= 1; --i) {
    if (i % b == 0) return i;
  }

  return 1;
}

std::vector<std::string> split(const std::string& str, char delim) {
    std::stringstream ss(str);
    std::string tok;

    std::vector<std::string> fields;
    while (std::getline(ss, tok, delim)) {
      fields.push_back(tok);
    }

    return fields;
}

void on(Map& map, const std::vector<std::string>& ops) {
  std::vector<std::string> reg = split(ops[1], 'x');
  int x = stoi(reg[0]);
  int y = stoi(reg[1]);

  for (int i = 0; i < y; ++i) {
    for (int j = 0; j < x; ++j) {
      map[i][j] = '#';
    }
  }
}

void rotate(Map& map, const std::vector<std::string>& ops) {
  int x = -1, y = -1;

  if (ops[1] == "row") y = stoi(ops[2].substr(2));
  else                 x = stoi(ops[2].substr(2));

  int delta = stoi(ops[4]);

  if (x != -1) {
    std::vector<char> cpy;
    int size = map.size();
    for (int i = 0; i < size; ++i) {
      cpy.push_back(map[(i - delta + size) % size][x]);
    }
    for (int i = 0; i < size; ++i) {
      map[i][x] = cpy[i];
    }
  } else {
    std::vector<char> cpy;
    int size = map[0].size();
    for (int i = 0; i < size; ++i) {
      cpy.push_back(map[y][(i - delta + size) % size]);
    }
    for (int i = 0; i < size; ++i) {
      map[y][i] = cpy[i];
    }
  }
}

void printMap(Map& map) {
  for (int i = 0; i < map.size(); ++i) {
      for (int j = 0; j < map[i].size(); ++j) {
        std::cout << map[i][j];
      }
      std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  Map map(6, std::vector<char>(50, '.'));
  std::string command;

  while (std::getline(std::cin, command)) {
    std::vector<std::string> fields = split(command, ' ');
    if (fields[0] == "rect") {
      on(map, fields);
    } else if (fields[0] == "rotate") {
      rotate(map, fields);
    }
    printMap(map);
    std::cout << "--------------------------------" << std::endl;
  }

  int c = 0;
  for (int i = 0; i < map.size(); ++i) {
      for (int j = 0; j < map[i].size(); ++j) {
        if (map[i][j] == '#') ++c;
      }
  }
  std::cout << c << std::endl;

  return 0;
}
