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
void editTeamRecord(TeamRecord array[]);
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

    char recordEditSelection;
    cout << "Would you like to edit a record? Y/N" << endl;
    cin >> recordEditSelection;

    if(recordEditSelection == 'Y' or recordEditSelection == 'y')
        editTeamRecord(recordArray);

    delete[] recordArray;
    system("pause");
}

void editTeamRecord(TeamRecord array[]){
    int teamSelect;
    int statSelect;
    cout << "Type the number of the team to select it." << endl;
    cin >> teamSelect;
    teamSelect--;

    cout << "Do you want to edit wins, losses, or ties?" << endl;
    cout << "1.) Wins" << endl
         << "2.) Losses" << endl
         << "3.) Ties" << endl;
    cin >> statSelect;

    switch(statSelect){
        case 1:

        case 2:

        case 3:

        default:
        
    }

    while(statSelect != 'Q' or statSelect != 'q'){
        int statEdit = 0;
        if(statSelect == 'W' or statSelect == 'w'){
            cout << "How many wins do the " + array[teamSelect].teamName + " have?" << endl;
            cin >> statEdit;
            array[teamSelect].win = statEdit;
            cout << endl;
            cout << "Do you want to edit losses or ties?" << endl;
            cout << "Enter Q to continue" << endl;
            cin >> statSelect;
        }
        if (statSelect == 'L' or statSelect == 'l'){
            cout << "How many losses do the " + array[teamSelect].teamName + " have?" << endl;
            cin >> statEdit;
            array[teamSelect].loss = statEdit;
            cout << endl;
            cout << "Do you want to edit wins or ties?" << endl;
            cout << "Enter Q to continue" << endl;
            cin >> statSelect;
        }
        if (statSelect == 'T' or statSelect == 't'){
            cout << "How many ties do the " + array[teamSelect].teamName + " have?" << endl;
            cin >> statEdit;
            array[teamSelect].tie = statEdit;
            cout << endl;
            cout << "Do you want to edit wins or losses?" << endl;
            cout << "Enter Q to continue" << endl;
            cin >> statSelect;

        } else {
            cout << "Invalid Choice: Choose the correct option or press Q to quit." << endl;
            cin >> statSelect;
        }
    }

    fstream file("records.txt");
    int count = 0;
    string line;
    while (getline(file, line)){
        count += 1;
    }

    file.close();
    file.open("records.txt", ios::out | ios::trunc);
        if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            file << array[i].teamName + "," + 
                    to_string(array[i].win) + "," +
                    to_string(array[i].loss) + "," +
                    to_string(array[i].tie) << endl;
        }
    }
    else { cout << "Error: File Not Open" << endl; }
    file.close();

    printTeamRecords();

}
