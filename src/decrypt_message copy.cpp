#include <iostream>
#include <string>
#include <vector>

void printVector(const std::vector<int> &v) {
  for (const auto &e : v)
    std::cout << e << ",";
  std::cout << "\n";
}

const int FIX_VALUE = 26;
const int LOW_RANGE = 97;
const int HIGH_RANGE = 122;
int getClosest(int sum, int value) {
  auto top = ceil((sum - value) / static_cast<double>(FIX_VALUE));
  auto low = floor((sum - value) / static_cast<double>(FIX_VALUE));
  int iTop = top * FIX_VALUE;
  int iLow = low * FIX_VALUE;
  int topValue = iTop + value;
  int lowValue = iLow + value;
  int diffTop = topValue - sum;
  int diffLow = sum - lowValue;
  return diffTop > diffLow ? lowValue : topValue;
}

std::string decrypt(const std::string &message) {
  std::vector<int> values(message.size());
  int prev_value = 0;
  for (size_t i = 0; i < message.size(); i++) {
    if (i == 0) {
      values[i] = static_cast<int>(message[i]);
      prev_value = values[i];
    } else {
      int value = static_cast<int>(message[i]);
      prev_value = getClosest(prev_value + value, value);
      values[i] = prev_value;
    }
  }
  std::string result{message};
  for (size_t i = 0; i < values.size(); i++) {
    if (i == 0) {
      result[i] = static_cast<char>(values[i] - 1);
    } else {
      auto letter = static_cast<char>(values[i] - values[i - 1]);
      if (letter > HIGH_RANGE)
        letter -= FIX_VALUE;
      if (letter < LOW_RANGE)
        letter += FIX_VALUE;
      result[i] = letter;
    }
  }
  return result;
}
int main() {
  std::cout << decrypt("dnotq") << "\n";
  std::cout << decrypt("flgxswdliefy") << "\n";
  std::cout << decrypt("rajsb") << "\n";
  return 0;
}