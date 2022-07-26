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

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
  if (year == 1918) {
    return "26.09.1918";
  }
  bool leapYear = false;
  if (year <= 1917) {
    // use Julian Calendar
    if (year % 4 == 0)
      leapYear = true;
  } else {
    if (year % 4 == 0) {
      if (year % 100 != 0)
        leapYear = true;
      else if (year % 400 == 0)
        leapYear = true;
    }
  }
  stringstream ss;
  if (leapYear)
    ss << "12.09.";
  else
    ss << "13.09.";
  ss << year;
  return ss.str();
}

int main() {
  string year_temp;
  getline(cin, year_temp);
  int year = stoi(ltrim(rtrim(year_temp)));
  string result = dayOfProgrammer(year);
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
