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
  ++iter;

  return res;
}

void expand(std::string& str, int& start, int depth) {
  std::pair<int, int> mult;

  int ex1, ex2;
  ex1 = ex2 = start;
  mult = extract(str, ex2);

  std::string toMult(str.begin() + ex2, str.begin() + ex2 + mult.first);

  str.erase(ex1, ex2 - ex1 + mult.first);

  int length = toMult.length();
  for (int i = 0; i < length; ++i) {
    while (toMult[i] == '(') {
      expand(toMult, i, depth + 1);
      length = toMult.length();
    }
  }

  for (int i = 0; i < mult.second; ++i) {
    str.insert(start, toMult);
  }
  start += toMult.length() * mult.second;



  /* std::string toMult{}; */
  /* iter = tmp + mult.first * mult.second; */
  /* while (mult.second > 1) { */
  /*   toMult += str.substr(tmp, mult.first); */
  /*   --mult.second; */
  /* } */
  /* str.insert(tmp, toMult); */

}

int main() {
  std::string line;

  while (std::getline(std::cin, line)) {
    for (int iter = 0; iter < line.length(); ++iter) {
      while (line[iter] == '(') {
        expand(line, iter, 0);
      }
    }
    std::cout << line.length() << std::endl;
  }



  return 0;
}
