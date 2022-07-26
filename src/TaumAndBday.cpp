#include<vector>
#include<math.h>
#include<fstream>
#include<iostream>
#include<functional>
#include<string>
#include<limits>
/*
 * Complete the 'taumBday' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER b
 *  2. INTEGER w
 *  3. INTEGER bc
 *  4. INTEGER wc
 *  5. INTEGER z
 */
using namespace std;
long long taumBday(long long b, long long w, long long bc, long long wc, long long z) {
    if(bc==wc || z>=(abs(wc-bc))) { 
        // // If the cost is the same or the cost of conversion is higher
        // // Just return the normal cost
        // std::cout << "returning costs\n";
        // std::cout << "White:" << w << " Pieces:" << wc << "Result:" << (w*wc) <<  "\n";
        // std::cout << "Black:" << b << " Pieces:" << bc << "Result:" << (b*static_cast<long long>(bc)) << "\n";
        return static_cast<long long>(w*wc) + static_cast<long long>(b*bc);
    }
    if(bc>wc){
        // If black cost is higher we buy all items white
        long long totalCost=(b+w) * wc;
        // And convert the black to white
        return totalCost + (b*z);        
    }
    long long totalCost=(b+w) * bc;
    return totalCost + (w*z);  
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

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));
    std::cout << "Limits of integer:"<< std::numeric_limits<int>::max() << "\n";
    std::cout << "Limits of long:"<< std::numeric_limits<long long>::max() << "\n";
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int b = stoi(first_multiple_input[0]);

        int w = stoi(first_multiple_input[1]);

        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int bc = stoi(second_multiple_input[0]);

        int wc = stoi(second_multiple_input[1]);

        int z = stoi(second_multiple_input[2]);

        long long result = taumBday(b, w, bc, wc, z);

        cout << result << "\n";
    }


    return 0;
}
