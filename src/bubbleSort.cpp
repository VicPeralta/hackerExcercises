#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int> &v) {
  std::cout << "[";
  for (const auto &e : v)
    std::cout << e << ",";
  std::cout << "]\n";
}

// Implements bubble sort algorithm
std::vector<int> sort(std::vector<int> &v) {
  bool isSorted = false;
  while (!isSorted) {
    isSorted=true;
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i] > v[i + 1]) {
        std::swap(v[i], v[i + 1]);
        isSorted=false;
      }
    }
  }
  return v;
}

int main() {
  std::vector<int> v{1000, -2, 48, 28, 2, 3, 1, 44, 100, 200};
  print(sort(v));
  return 0;
}