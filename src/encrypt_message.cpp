#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int moveToRange(int value) {
  const int FIX_VALUE = 26;
  const int LOW_RANGE = 97;
  const int HIGH_RANGE = 122;

  int result = value;
  if (result < LOW_RANGE)
    while (result < LOW_RANGE)
      result += FIX_VALUE;
  else
    while (result > HIGH_RANGE)
      result -= FIX_VALUE;
  return result;
}

std::string encrypt(const std::string &words) {
  std::string result{words};
  int sum{1};
  for (size_t i = 0; i < words.size(); i++) {
    int ch = tolower(words[i]);
    result[i] = moveToRange(ch + sum);
    sum += ch;
  }
  return result;
}

int main(int argc, char *argv[]) {
  if (argc != 2)
    return 1;
  std::cout << encrypt(argv[1]) << "\n";
  return 0;
}
