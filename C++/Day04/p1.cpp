#include <iostream>
#include <vector>
#include <regex>
#include <string>

typedef struct room {
  std::string name;
  int id;
  std::string checksum;
} Room;

Room createRoom(std::string& r) {
  Room room{};

  std::smatch match;
  std::regex pat("(.*)-(\\d+)\\[([a-z]{5})\\]");

  std::regex_match(r, match, pat);

  room.name = match[1];
  room.id = std::stoi(match[2]);
  room.checksum = match[3];

  return room;
}

bool validRoom(Room& r) {

  std::map<char, int> freq;

  for (auto ch = r.checksum.begin(); ch != r.checksum.end(); ++ch) {
    freq[*ch] = 0;
  }

  for (auto ch = r.name.begin(); ch != r.name.end(); ++ch) {
    if (*ch == '-') continue;
    freq[*ch]++;
  }

  std::vector<std::pair<char, int>> items{};

  for (auto iter = freq.begin(); iter != freq.end(); ++iter) {
    items.push_back(*iter);
  }

  auto cmp = [](std::pair<char, int> const& a, std::pair<char, int> const& b) {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
  };

  std::sort(items.begin(), items.end(), cmp);


  for (auto p = 0; p < 5; ++p) {
    if (items[p].first != r.checksum[p]) return false;
  }

  return true;
}

int main() {

  std::string room;
  int c = 0;

  while (std::getline(std::cin, room)) {

    Room r = createRoom(room);

    if (validRoom(r)) {
      std::cout << "Room " << r.name << " is valid" << std::endl;
      c += r.id;
    }
  }

  std::cout << c << std::endl;

  return 0;
}
