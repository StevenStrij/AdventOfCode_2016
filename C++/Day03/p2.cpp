#include <iostream>
#include <string>
#include <sstream>

bool validTri(int* tri) {
  return tri[0] + tri[1] > tri[2] && tri[1] + tri[2] > tri[0] && tri[0] + tri[2] > tri[1];
}

void printTri(int* tri) {
  std::cout << tri[0] << " " << tri[1] << " " << tri[2] << std::endl;
}

int main() {
  std::string tok;

  int tri1[3], tri2[3], tri3[3];
  int s1, s2, s3;
  int p = 0;
  int c = 0;

  while (std::getline(std::cin, tok)) {
    std::stringstream ss(tok);

    ss >> s1 >> s2 >> s3;
    tri1[p] = s1;
    tri2[p] = s2;
    tri3[p] = s3;

    if (p == 2) {
      if (validTri(tri1)) {
        std::cout << "Valid: ";
        printTri(tri1);
       ++c;
      }
      if (validTri(tri2)) {
        std::cout << "Valid: ";
        printTri(tri2);
       ++c;
      }
      if (validTri(tri3)) {
        std::cout << "Valid: ";
        printTri(tri3);
       ++c;
      }
    }

    p = (p + 1) % 3;
  }

  std::cout << c << std::endl;

  return 0;
}
