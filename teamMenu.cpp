// Program file to read in a text file of team records.
// Should create an array of TeamRecord structs to display
// to user. User can update the record on their own if 
// they choose.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "teamrecord.h"
using namespace std;

void editTeamRecord(TeamRecord array[]);
void mainMenu();
void printTeamRecords() {
    system("cls");

    //declaring integer counter for number of lines in input file
    int numOfTeams = 0;

    fstream file("records.txt");
    string teamName, teamWin, teamLoss, teamTie, tempData;
    string line;


    // count the number of teams
    while (getline(file, line)){
        numOfTeams += 1;
    }

    //Creating the dynamic array of TeamRecord structs
    TeamRecord* recordArray = new TeamRecord[numOfTeams];

    file.close();
    file.open("records.txt");

    //Parsing through the file line by line to set the data
    //members of the struct.
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

    //This code handles the display output of the array contents
    //It is set to display 16 of the teams before waiting for 
    //the user to contiue.
    int outputCounter = 0;
    int outputControl = 15;
    for (int i = 0; i < numOfTeams; i++) {
        if (i%16 == 0) {
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
            outputControl += 16;
        }
        outputCounter++;
    }
    file.close();

    //Selecting whether or not to edit a teams record.
    char recordEditSelection;
    cout << "Would you like to edit a record? Y/N" << endl;
    cin >> recordEditSelection;

    if (recordEditSelection == 'Y' or recordEditSelection == 'y')
        editTeamRecord(recordArray);
    else
        delete[] recordArray;
        mainMenu();

    system("pause");
}

//Function is passed the dynamic array created above. This function
//is then used to manipulate the elements of that array.
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
    
    int statEdit = 0;
    switch(statSelect){
        case 1:
            cout << "How many wins do the " + array[teamSelect].teamName + " have?" << endl;
            cin >> statEdit;
            array[teamSelect].win = statEdit;
            cout << endl;
            break;

        case 2:
            cout << "How many losses do the " + array[teamSelect].teamName + " have?" << endl;
            cin >> statEdit;
            array[teamSelect].loss = statEdit;
            cout << endl;
            break;

        case 3:
            cout << "How many ties do the " + array[teamSelect].teamName + " have?" << endl;
            cin >> statEdit;
            array[teamSelect].tie = statEdit;
            cout << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
            editTeamRecord(array);
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
