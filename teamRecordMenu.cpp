#ifndef TEAMRECORDMENU_CPP
#define TEAMRECORDMENU_CPP


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
#include "linearSearch.h"
using namespace std;

void teamRecordMenu();
TeamRecord* createRecordArray(int& size);
TeamRecord* printTeamRecords(TeamRecord* recordArray, int& size);
TeamRecord* editTeamRecord(TeamRecord* recordArray, int& size);
TeamRecord* searchRecords(TeamRecord* recordArray, int& size);
TeamRecord* sortRecords(TeamRecord* recordArray, int& size);
TeamRecord* selectionSortAscending(TeamRecord* recordArray, int& size);
TeamRecord* selectionSortDescending(TeamRecord* recordArray, int& size);
void mainMenu();

void teamRecordMenu(){
    int size;
    TeamRecord* recordArray = createRecordArray(size);

    int selection;
    cout << "What would you like to do?" << endl;
    cout << "1.) Print records" << endl;
    cout << "2.) Search Records" << endl;
    cout << "3.) Sort Records" << endl;
    cout << "4.) Return to Main Menu." << endl;
    cin >> selection;
    cin.ignore();
    
    switch (selection){
        case 1:
            recordArray = printTeamRecords(recordArray, size);
            break;

        case 2:
            recordArray = searchRecords(recordArray, size);
            break;

        case 3:
            recordArray = sortRecords(recordArray, size);
            break;

        case 4:
            delete[] recordArray;
            mainMenu();
            break;
        
        default:
            cout << "Invalid Choice. Please select again." << endl;
            system("pause");
            teamRecordMenu();
            break;
    }
    teamRecordMenu();
}


TeamRecord* createRecordArray(int& size) {
    system("cls");

    //declaring integer counter for number of lines in input file
    size = 0;

    fstream file("records.txt");
    string teamName, teamWin, teamLoss, teamTie, tempData;
    string line;


    // count the number of teams
    while (getline(file, line)){
        size += 1;
    }

    //Creating the dynamic array of TeamRecord structs
    TeamRecord* recordArray = new TeamRecord[size];

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
        recordArray[i].percentage = (recordArray[i].win / 
                                    (recordArray[i].win + 
                                     recordArray[i].loss + 
                                     recordArray[i].tie))*100;

        i++;
    }
    file.close();
    return recordArray;
}

TeamRecord* printTeamRecords(TeamRecord* recordArray, int& size) {
    //This code handles the display output of the array contents
    //It is set to display 16 of the teams before waiting for 
    //the user to contiue.
    int outputCounter = 0;
    int outputControl = 15;
    for (int i = 0; i < size; i++) {
        if (i%16 == 0) {
            cout << endl;
            cout << setfill(' ') << setw(10) << " " << "Team" 
                << setfill(' ') << setw(20) << " " << "Wins"
                << setfill(' ') << setw(7) << " " << "Losses"
                << setfill(' ') << setw(5) << " " << "Ties"
                << setfill(' ') << setw(5)  << " " << "Percentage" << endl;
            cout << endl;
        }

        int counter = i + 1;
        cout << left;
        cout << setw(2) << counter  << ".) ";
        cout << setw(30) << recordArray[i].teamName << " "
            << setw(10) << recordArray[i].win << " "
            << setw(10) << recordArray[i].loss << " "
            << setw(10) << recordArray[i].tie << " "
            << setw(5) << fixed << setprecision(0) << right
                        << recordArray[i].percentage << endl;

        if (outputCounter == outputControl) { 
            system("pause");
            outputControl += 16;
        }
        outputCounter++;
    }

    //Selecting whether or not to edit a teams record.
    char recordEditSelection;
    cout << "Would you like to edit a record? Y/N" << endl;
    cin >> recordEditSelection;

    if (recordEditSelection == 'Y' or recordEditSelection == 'y')
        editTeamRecord(recordArray, size);

    system("pause");
    return recordArray;
}

//Function is passed the dynamic array created above. This function
//is then used to manipulate the elements of that array.
TeamRecord* editTeamRecord(TeamRecord* recordArray, int& size){
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
            cout << "How many wins do the " + recordArray[teamSelect].teamName + 
                    " have?" << endl;
            cin >> statEdit;
            recordArray[teamSelect].win = statEdit;
            cout << endl;
            break;

        case 2:
            cout << "How many losses do the " + recordArray[teamSelect].teamName + 
                    " have?" << endl;
            cin >> statEdit;
            recordArray[teamSelect].loss = statEdit;
            cout << endl;
            break;

        case 3:
            cout << "How many ties do the " + recordArray[teamSelect].teamName + 
                    " have?" << endl;
            cin >> statEdit;
            recordArray[teamSelect].tie = statEdit;
            cout << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
            editTeamRecord(recordArray, size);
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
            file << recordArray[i].teamName + "," +
                    to_string(recordArray[i].win) + "," +
                    to_string(recordArray[i].loss) + "," +
                    to_string(recordArray[i].tie) + "," +
                    to_string(recordArray[i].percentage) << endl;
        }
    }
    else { cout << "Error: File Not Open" << endl; }
    file.close();

    return recordArray;
}

TeamRecord* searchRecords(TeamRecord* recordArray, int& size) {
    int selection, amountToDisplay;
    cout << "Search For: " << endl;
    cout << "1.) Wins" << endl;
    cout << "2.) Losses" << endl;
    cout << "3.) Ties" << endl;
    cin >> selection;

    switch (selection) {
        case 1:
            cout << "Teams with how many wins should be displayed?" << endl;
            cin >> amountToDisplay;
            recordArray = linearSearchWins(recordArray, size, amountToDisplay);
            system("pause");
            teamRecordMenu();
            break;
        case 2:
            cout << "Teams with how many losses should be displayed?" << endl;
            cin >> amountToDisplay;
            recordArray = linearSearchLosses(recordArray, size, amountToDisplay);
            system("pause");
            break;
        case 3:
            cout << "Teams with how many ties should be displayed?" << endl;
            cin >> amountToDisplay;
            recordArray = linearSearchTies(recordArray, size, amountToDisplay);
            system("pause");
            break;
    }
    return recordArray;
}

TeamRecord* sortRecords(TeamRecord* recordArray, int& size) {
    cout << "Sort by:" << endl;
    cout << "1.) Wins" << endl;
    cout << "2.) Losses" << endl;
    cout << "3.) Ties" << endl;
    int selection;
    cin >> selection;

    switch (selection)
    {
        int selection2;
        case 1:
            cout << "What Order?" << endl;
            cout << "1.) Ascending" << endl;
            cout << "2.) Descending" << endl;
            cin >> selection2;
            if (selection2 == 1) {
                recordArray = selectionSortAscending(recordArray, size);
            }
            else if (selection2 == 2) {
                recordArray = selectionSortDescending(recordArray, size);
            }
            break;

        case 2:

        default:
            break;
    }
    return recordArray;
}

TeamRecord* selectionSortAscending(TeamRecord* recordArray, int& size) {
    int i, j, indexSmallest;
    for (i = 0; i < size - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
            for (j = i + 1; j < size; ++j) {

                if (recordArray[j].win < recordArray[indexSmallest].win) {
                    indexSmallest = j;
                }
            }

        // Swap numbers[i] and numbers[indexSmallest]
        TeamRecord temp;
        temp = recordArray[i];
        recordArray[i] = recordArray[indexSmallest];
        recordArray[indexSmallest] = temp;
    }
    recordArray = printTeamRecords(recordArray, size);
    cout << "Leaving selectionSort" << endl;
    system("pause");
    return recordArray;
}

TeamRecord* selectionSortDescending(TeamRecord* recordArray, int& size) {
    int i, j, indexSmallest;
    for (i = 0; i < size - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < size; ++j) {

            if (recordArray[j].win > recordArray[indexSmallest].win) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        TeamRecord temp;
        temp = recordArray[i];
        recordArray[i] = recordArray[indexSmallest];
        recordArray[indexSmallest] = temp;
    }
    recordArray = printTeamRecords(recordArray, size);
    cout << "Leaving selectionSort" << endl;
    system("pause");
    return recordArray;
}
#endif
