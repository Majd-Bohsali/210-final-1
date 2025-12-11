// COMSC210 | Final Exam 1 | Majd Bohsali
// IDE used: Visaul Studio Code
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() { 
    map<string, int> airportLog; 

    ifstream inputFile("210-final-1-FA25.txt"); 

    string airportOrigin, airportDest; 

    if(inputFile.is_open()) { 
        while(inputFile >> airportOrigin >> airportDest) { 
            airportLog[airportOrigin] += 1;
            airportLog[airportDest] += 1; 
        }
        inputFile.close();
    } else { 
        cout << "File could not open";
    }

    for(auto it = airportLog.begin(); it != airportLog.end(); it++) { 
        int airportCount = it->second; 
        cout << it->first << ": " << airportCount << endl; 
    }

    return 0; 
}