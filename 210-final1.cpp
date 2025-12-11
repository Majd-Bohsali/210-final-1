// COMSC210 | Final Exam 1 | Majd Bohsali
// IDE used: Visaul Studio Code
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void printWithinRange(map<string, int>, int, int); 

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

    int highestCount = 0; 
    vector<string> highestAirportsCount;
    cout << "All airport traffic counts: " << endl;
    for(auto it = airportLog.begin(); it != airportLog.end(); it++) { 
        int airportCount = it->second; 
        cout << it->first << ": " << airportCount << endl; 

        // Got code to find highest coutn while handing ties from the Extra Credit 2 Lab from Week 16
        if(airportCount == highestCount) { 
            highestAirportsCount.push_back(it->first); 
        } else if (airportCount > highestCount) { 
            highestCount = airportCount; 
            highestAirportsCount.clear(); 
            highestAirportsCount.push_back(it->first); 
        }
    }

    cout << endl << "Busiest airport(s) with count " << highestCount << endl; 
    for(int i = 0; i < highestAirportsCount.size(); i++) { 
        cout << highestAirportsCount.at(i) << " " << airportLog[highestAirportsCount.at(i)]<< endl; 
    }

    cout << endl;
    printWithinRange(airportLog, 5, 8); 
    cout << endl;
    printWithinRange(airportLog, 8, 15); 

    return 0; 
}
   
void printWithinRange(map<string, int> airportLog, int low, int high) { 
    cout << "Airports with traffic in range [" << low << ", " << high << "]" << endl;
    for(auto it = airportLog.begin(); it != airportLog.end(); it++) { 
        int rangeCount = it->second; 
        if(rangeCount >= low && rangeCount <= high) { 
            cout << it->first << " " << it->second << endl; 
        }
    }
}