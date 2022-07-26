#include <iostream>
#include <vector>

void printVector(std::vector<int> &vector) {
  for (auto const &element : vector)
    std::cout << element << ",";
  std::cout << "\n";
}

void printVectorRange(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end) {
  for (auto i = begin; i != end; i++) {
    std::cout << *i << ",";
  }
  std::cout << "\n";
}

int partition(std::vector<int>::iterator begin, std::vector<int>::iterator end,
              int pivotIndex) {
  int distance = std::distance(begin, end);
  for (int i = 0; i < distance; i++) {
    if (*(begin + i) < *(begin + pivotIndex)) {
      int p = i;
      while (p != pivotIndex) {
        std::swap(*(begin + p), *(begin + (p - 1)));
        p--;
      }
      pivotIndex = p + 1;
    }
  }
  return pivotIndex;
}

void quickRecursive(std::vector<int>::iterator begin,
                    std::vector<int>::iterator end) {
  if (std::distance(begin, end) < 2)
    return;
  auto p = partition(begin, end, 0);
  // Less than
  quickRecursive(begin, begin + p);
  // Greater than
  quickRecursive(begin + p + 1, end);
}

std::vector<int> &quickSort(std::vector<int> &vector) {
  quickRecursive(vector.begin(), vector.end());
  return vector;
}

int main() {
  std::vector<int> data{20, 19, 18, 18, 17, 2};
  std::cout << "Before sorting:";
  printVector(data);
  quickSort(data);
  std::cout << "After sorting:";
  printVector(data);
  return 0;
}