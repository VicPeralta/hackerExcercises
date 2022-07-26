#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void print(const std::vector<int> &v) {
  for (const int &e : v)
    std::cout << e << ",";
  std::cout << "\n";
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
/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int formingMagicSquare(vector<vector<int>> s) {
  std::vector<int> flat(9);
  for (int i = 0, t = 0; i < 3; i++, t += 3) {
    flat[t] = s[i][0];
    flat[t + 1] = s[i][1];
    flat[t + 2] = s[i][2];
  }
  std::vector<int> diffs(8);
  const std::vector<std::vector<int>> magics = {
      {2, 7, 6, 9, 5, 1, 4, 3, 8}, {2, 9, 4, 7, 5, 3, 6, 1, 8},
      {4, 3, 8, 9, 5, 1, 2, 7, 6}, {4, 9, 2, 3, 5, 7, 8, 1, 6},
      {6, 1, 8, 7, 5, 3, 2, 9, 4}, {6, 7, 2, 1, 5, 9, 8, 3, 4},
      {8, 1, 6, 3, 5, 7, 4, 9, 2}, {8, 3, 4, 1, 5, 9, 6, 7, 2}};
  for (int index = 0; index < magics.size(); index++) {
    int diff = 0;
    for (int i = 0; i < 9; i++) {
      diff += abs(magics[index][i] - flat[i]);
    }
    diffs[index] = diff;
  }
  return *std::min_element(diffs.begin(), diffs.end());
}

int main() {
  vector<vector<int>> s(3);
  for (int i = 0; i < 3; i++) {
    s[i].resize(3);

    string s_row_temp_temp;
    getline(cin, s_row_temp_temp);

    vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

    for (int j = 0; j < 3; j++) {
      int s_row_item = stoi(s_row_temp[j]);

      s[i][j] = s_row_item;
    }
  }

  int result = formingMagicSquare(s);
  cout << result << "\n";
  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}