#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    // Declare second integer, double, and String variables.
    int myInt{0};
    double myDouble{0.00};
    string myString;
    
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    std::cin >> myInt >> myDouble;

	std::cin.ignore();
	
    std::getline(std::cin,myString);
    // Print the sum of both integer variables on a new line.
    std::cout <<  (myInt + i) << "\n";

    // Print the sum of the double variables on a new line.
    std::cout << std::fixed <<setprecision(1) << (myDouble + d) << "\n";

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    std::cout << s << myString << "\n";

    return 0;
}