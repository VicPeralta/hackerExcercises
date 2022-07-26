#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {
  int steps = 0;
  if (p > (n / 2)) { // closer to the end
    if (n % 2==0) {
      if (p == n)
        return 0;
      while (n>p) {
        n -= 2;
        steps++;
      }
    } else {
      if (p == n || p == n - 1)
        return 0;
        n--;
      while (n>p) {
        n -= 2;
        steps++;
      }
    }
  }else { // Closer to the start
      if(p==1) return 0;
      int start=1;
      while ( p>start) {
        start += 2;
        steps++;
      }
    }
    return steps;
}

int main() {
  string n_temp;
  getline(cin, n_temp);
  int n = stoi(ltrim(rtrim(n_temp)));
  string p_temp;
  getline(cin, p_temp);
  int p = stoi(ltrim(rtrim(p_temp)));
  int result = pageCount(n, p);
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