#include <iostream>
#include <string>
#include <vector>

const int FIX_VALUE = 26;
const int LOW_RANGE = 97;
const int HIGH_RANGE = 122;

int moveToRange(int value) {
  int result = value;
  if (result < LOW_RANGE)
    while (result < LOW_RANGE)
      result += FIX_VALUE;
  else
    while (result > HIGH_RANGE)
      result -= FIX_VALUE;
  return result;
}

std::string decrypt(const std::string &message) {
  int prev_sum = 1;
  std::string decodedMessage{message};
  for (size_t i = 0; i < message.size(); i++) {
    int value = message[i] - prev_sum;
    if (value < LOW_RANGE || value > HIGH_RANGE)
      value = moveToRange(value);
    decodedMessage[i] = value;
    prev_sum = (prev_sum + value) % FIX_VALUE;
  }
  return decodedMessage;
}

int main(int argc, char *argv[]) {
  if (argc != 2)
    return 1;
  std::cout << decrypt(argv[1]) << "\n";
  return 0;
}