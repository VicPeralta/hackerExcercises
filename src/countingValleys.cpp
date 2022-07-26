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
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
  int valleys=0;
  int seaLevel=0;
  bool inValley=false;
  for(const auto& c:path){
    if(c=='D')seaLevel--;
    else seaLevel++;
    if(seaLevel<0){
      if(!inValley){
        inValley=true;
        valleys++;
      }
    } else {
      inValley=false;
    }
  }
  return valleys;
}

int main()
{
    string steps_temp;
    getline(cin, steps_temp);
    int steps = stoi(ltrim(rtrim(steps_temp)));
    string path;
    getline(cin, path);
    int result = countingValleys(steps, path);
    cout << result << "\n";
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
