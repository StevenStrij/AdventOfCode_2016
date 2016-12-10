#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
  std::string line;
  int c = 0;


  while (std::getline(std::cin, line)) {
    char ch;
    bool inBrackets = false;
    bool valid = false;

    // True if in brackets
    std::map<std::string, bool> seqs{};

    std::cout << line << std::endl;
    for (int i = 0; i < line.length() - 2; ++i) {
      ch = line[i];
      if (ch == '[') inBrackets = true;
      if (ch == ']') inBrackets = false;

      if (line[i] == line[i + 2] && line[i] != line[i + 1]) {
        std::string sub(line.begin() + i, line.begin() + i + 3);
        std::string rev{sub[1], sub[0], sub[1]};
        std::cout << sub << std::endl;

        if (seqs.find(rev) != seqs.end()) {
          if (seqs[rev] == !inBrackets) {
            std::cout << "Found under " << sub << " -- " << rev << std::endl;
            valid = true;
            break;
          }
        }
        seqs[sub] = inBrackets;
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
