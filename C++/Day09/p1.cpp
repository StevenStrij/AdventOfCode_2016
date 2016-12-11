#include <iostream>
#include <vector>

std::pair<int, int> extract(const std::string& line, int& iter) {
  std::string num{};
  std::pair<int, int> res{};

  if (line[iter] == '(') ++iter;

  while (line[iter] != 'x') {
    num += line[iter];
    ++iter;
  }
  res.first = stoi(num);

  num = "";
  ++iter;
  while (line[iter] != ')') {
    num += line[iter];
    ++iter;
  }
  res.second = stoi(num);

  return res;
}

int main() {
  std::string str{};
  std::string line;

  while (std::getline(std::cin, line)) {
    str.append(line);
  }

  std::pair<int, int> mult;
  for (int iter = 0; iter < str.length();) {
    if (str[iter] == '(') {
      int tmp(iter);
      mult = extract(str, iter);
      str.erase(str.begin() + tmp, str.begin() + iter + 1);

      std::string toMult{};
      iter = tmp + mult.first * mult.second;
      while (mult.second > 1) {
        toMult += str.substr(tmp, mult.first);
        --mult.second;
      }
      str.insert(tmp, toMult);
    } else {
      ++iter;
    }
  }

  std::cout << str.length() << std::endl;

  return 0;
}
