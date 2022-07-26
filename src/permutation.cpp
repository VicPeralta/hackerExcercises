#include <algorithm>
#include <iostream>
#include <vector>

void print(const std::vector<int> &v) {
  for (const int &e : v)
    std::cout << e << ",";
  std::cout << "\n";
}

bool isMagic(std::vector<int> &s) {

  // const std::vector<std::vector<int>> magics = {
  //   {2, 7, 6, 9, 5, 1, 4, 3, 8},
  //   {2, 9, 4, 7, 5, 3, 6, 1, 8},
  //   {4, 3, 8, 9, 5, 1, 2, 7, 6},
  //   {4, 9, 2, 3, 5, 7, 8, 1, 6},
  //   {6, 1, 8, 7, 5, 3, 2, 9, 4},
  //   {6, 7, 2, 1, 5, 9, 8, 3, 4},
  //   {8, 1, 6, 3, 5, 7, 4, 9, 2},
  //   {8, 3, 4, 1, 5, 9, 6, 7, 2}
  // };
  // for(const auto& magic:magics){
  //   if(magic==s)return true;
  // }
  // return false;

  // check rows
  for (int t = 0; t < 9; t += 3) {
    if ((s[t] + s[t + 1] + s[t + 2]) != 15)
      return false;
  }
  // check columns
  for (int t = 0; t < 3; t += 1) {
    if ((s[t] + s[t + 3] + s[t + 6]) != 15)
      return false;
  }
  // Check diagonals
  if ((s[0] + s[4] + s[8]) != 15)
    return false;
  if ((s[2] + s[4] + s[6]) != 15)
    return false;
  return true;
}

int getMinMagicDiff(const std::vector<int> &v) {
  std::vector<int> diffs(8);
  const std::vector<std::vector<int>> magics = {
      {2, 7, 6, 9, 5, 1, 4, 3, 8}, {2, 9, 4, 7, 5, 3, 6, 1, 8},
      {4, 3, 8, 9, 5, 1, 2, 7, 6}, {4, 9, 2, 3, 5, 7, 8, 1, 6},
      {6, 1, 8, 7, 5, 3, 2, 9, 4}, {6, 7, 2, 1, 5, 9, 8, 3, 4},
      {8, 1, 6, 3, 5, 7, 4, 9, 2}, {8, 3, 4, 1, 5, 9, 6, 7, 2}};
  for (int index = 0; index < magics.size(); index++) {
    int diff = 0;
    for (int i = 0; i < 9; i++) {
      diff += abs(magics[index][i] - v[i]);
    }
    diffs[index] = diff;
  }
  return *std::min_element(diffs.begin(), diffs.end());
}

int main() {
  std::vector<int> v{5, 3, 4, 1, 5, 8, 6, 4, 2};
  // while (next_permutation(v.begin(), v.end())) {
  //   if (isMagic(v))
  //     print(v);
  // }
  std::cout << "Min diff: " << getMinMagicDiff(v) << "\n";
  return 0;
}