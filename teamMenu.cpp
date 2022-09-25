// Program file to read in a text file of team records.
// Should create an array of TeamRecord structs to display
// to user. User can update the record on their own if 
// they choose.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "teamrecord.h"


//This function takes in the file name selected earlier to open its respective
//roster file. This function creates a dynamic array with the contents of the file
//and calls the display function defined in the header file.

void printTeamRecords() {
    system("cls");

    //declaring integer counter for number of lines in input file
    int numOfTeams = 0;

    fstream file("records.txt");
    string teamName, teamWin, teamLoss, teamTie, tempData;
    string line;


    // count the number of players
    while (getline(file, line))
    {
        numOfTeams += 1;
    }

    //Creating the dynamic array of Player objects
    TeamRecord* recordArray = new TeamRecord[numOfTeams];

    file.close();
    file.open("records.txt");

    int i = 0;
    int winInput, lossInput, tieInput;
    while (getline(file, line)) {

        stringstream ss(line);
        getline(ss, teamName, ',');
        getline(ss, teamWin, ',');
        getline(ss, teamLoss, ',');
        getline(ss, teamTie, ',');
        getline(ss, tempData, '\n');

        winInput = stoi(teamWin);
        lossInput = stoi(teamLoss);
        tieInput = stoi(teamTie);

        recordArray[i].teamName = teamName;
        recordArray[i].win = winInput;
        recordArray[i].loss = lossInput;
        recordArray[i].tie = tieInput;

        i++;
    }

    int outputCounter = 0;
    int outputControl = 19;
    for (int i = 0; i < numOfTeams; i++) {
        if (i%20 == 0) {
            cout << endl;
            cout << setfill(' ') << setw(10) << " " << "Team" 
                << setfill(' ') << setw(20) << " " << "Wins"
                << setfill(' ') << setw(7) << " " << "Losses"
                 << setfill(' ') << setw(5)  << " " << "Ties" << endl;
            cout << endl;
        }

        int counter = i + 1;
        cout << left;
        cout << setw(2) << counter  << ".) ";
        cout << setw(30) << recordArray[i].teamName << " "
             << setw(10) << recordArray[i].win << " "
             << setw(10) << recordArray[i].loss << " "
             << setw(10) << recordArray[i].tie << " " << endl;

        if (outputCounter == outputControl) { 
            system("pause");
            outputControl += 20;
        }
        outputCounter++;
    }


    file.close();
    delete[] recordArray;
    system("pause");
}
