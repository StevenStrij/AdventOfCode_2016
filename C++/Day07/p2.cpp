#include <iostream>
#include <string>
#include <vector>
#include <set>

int main() {
  std::string line;
  int c = 0;


  while (std::getline(std::cin, line)) {
    bool inBrackets = false;
    bool valid = false;

    // True if in brackets
    std::set<std::string> in, out;

    std::cout << line << std::endl;
    for (int i = 0; i < line.length() - 2; ++i) {
      if (line[i] == '[') inBrackets = true;
      else if (line[i] == ']') inBrackets = false;
      else if (line[i] == line[i + 2] && line[i] != line[i + 1]) {
        std::string sub{line[i], line[i + 1]};
        std::string rev{line[i + 1], line [i]};
        std::cout << sub << std::endl;

        if   (inBrackets) in.insert(rev);
        else              out.insert(sub);
      }
    }

    for (std::string i: in) {
      if (out.find(i) != out.end()) {
        valid = true;
        break;
      }
    }

    if (valid) {
      ++c;
      std::cout << line << " is valid" << std::endl;
    }
    std::cout << "------------------------"<< std::endl;
  }

  std::cout << c << std::endl;
  return 0;
}
