// COMSC210 | Final Exam 1 | Majd Bohsali
// IDE used: Visaul Studio Code
#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int main() { 
    map<string, int> airportLog; 

    ifstream inputFile("210-final-1-FA25"); 

    if(inputFile.is_open()) { 

        inputFile.close();
    } else { 
        cout << "File could not open"
    }

    return 0; 
}