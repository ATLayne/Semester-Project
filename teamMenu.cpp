// Program file to read in a text file of team records.
// Should create an array of TeamRecord structs to display
// to user. User can update the record on their own if 
// they choose.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "struct.h"


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

        //recordArray[i] = {teamName, winInput, lossInput, tieInput};
        recordArray[i].teamName = teamName;
        recordArray[i].win = winInput;
        recordArray[i].loss = lossInput;
        recordArray[i].tie = tieInput;

        i++;
    }

    // int outputCounter = 0;
    // int outputControl = 19;
    for (int i = 0; i < numOfTeams; i++) {
        cout << recordArray[i].teamName << " " 
             << recordArray[i].win << " "
             << recordArray[i].loss << " "
             << recordArray[i].tie << endl;
        // if (i%20 == 0) {
        //     cout << endl;
        //     cout << setfill(' ') << setw(10) << " " << "Name" 
        //         << setfill(' ') << setw(12) << " " << "Number"
        //         << setfill(' ') << setw(12) << " " << "Age"
        //          << setfill(' ') << setw(4)  << " " << "Position" << endl;
        //     cout << endl;
        // }

        // int counter = i + 1;
        // cout << right;
        // cout << setw(2) << counter  << ".) ";
        // playerArray[i].display();

        // if (outputCounter == outputControl) { 
        //     system("pause");
        //     outputControl += 20;
        // }
        // outputCounter++;
    }


    file.close();
    delete[] recordArray;
    system("pause");
}
