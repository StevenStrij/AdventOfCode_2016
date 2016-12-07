#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
  std::vector<std::map<char, int>> freqs{};
  std::string line{};

  while (std::getline(std::cin, line)) {
    for (int i = 0; i < line.length(); ++i) {
      if (freqs.size() < i + 1) freqs.push_back(std::map<char, int>());
      freqs[i][line[i]]++;
    }
  }

  std::cout << "Done" << std::endl;

  for (std::map<char, int> m : freqs) {
    auto max = std::min_element(m.begin(), m.end(),
        [] (const auto& a, const auto& b) {
          return a.second < b.second;
        });

    std::cout << max->first;
  }
  std::cout << std::endl;

  return 0;
}
