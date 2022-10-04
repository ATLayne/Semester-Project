//Austin Layne
//Nathaniel Moreno


#ifndef ROSTERS_CPP
#define ROSTERS_CPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
//#include "player.h"
#include "rostermenus.cpp"
using namespace std;

void rosterOptions(Player array[], int playerCount);
void createRosterArray(string teamName);
void mainMenu();

void createRosterArray(string teamName) {
    system("cls");

    cout << teamName << "\n" << endl;

    //declaring integer counter for number of lines in input file
    int numOfPlayers = 0;

    fstream file(teamName);
    string playerNumber, playerName, playerAge, playerPOS, tempData;
    string line;

    // count the number of players
    while (getline(file, line)) {
        numOfPlayers += 1;
    }

    //Creating the dynamic array of Player objects
    Player* playerArray = new Player[numOfPlayers];

    file.close();
    file.open(teamName);

    int i = 0;
    int number, age;
    while (getline(file, line)) {

        stringstream ss(line);
        getline(ss, playerNumber, ',');
        getline(ss, playerName, ',');
        getline(ss, playerAge, ',');
        getline(ss, playerPOS, ',');
        getline(ss, tempData, ',');

        if (playerNumber == "") {
            number = 0;
        }
        else {
            number = stoi(playerNumber);
        }

        if (playerAge == "") {
            age = 0;
        }
        else {
            age = stoi(playerAge);
        }

        playerArray[i].setPlayerInfo(playerName, number, age, playerPOS);
        i++;
    }

    cout << "Created Roster Array." << endl;
    system("pause");

    rosterOptions(playerArray, numOfPlayers);
}

//This function takes in the file name selected earlier to open its respective
//roster file. This function creates a dynamic array with the contents of the file
//and calls the display function defined in the header file.
void printRoster(Player array[], int playerCount) {

    int outputCounter = 0;
    int outputControl = 19;
    for (int i = 0; i < playerCount; i++) {
        if (i%20 == 0) {
            cout << endl;
            cout << setfill(' ') << setw(10) << " " << "Name" 
                << setfill(' ') << setw(12) << " " << "Number"
                << setfill(' ') << setw(12) << " " << "Age"
                 << setfill(' ') << setw(4)  << " " << "Position" << endl;
            cout << endl;
        }

        int counter = i + 1;
        cout << right;
        cout << setw(2) << counter  << ".) ";
        array[i].display();

        if (outputCounter == outputControl) { 
            system("pause");
            outputControl += 20;
        }
        outputCounter++;
    }
    system("pause");
    rosterOptions(array, playerCount);
}

//This function takes in the file name selected earlier to open its respective
//roster file. This function reads the amount of lines in the selected file
//and creates a dynamic array with one extra element

void addToRoster(Player array[], int playerCount) {
    int addNumber, addAge;
    string addName, addPOS;
    char continueSelect;
    fstream file;

    cout << "What is the players name?" << endl;
    getline(cin, addName);

    cout << "What is the players number?" << endl;
    cin >> addNumber;

    cout << "What is the players age?" << endl;
    cin >> addAge;

    cout << "What is the players Position?" << endl;
    cin.ignore();
    getline(cin, addPOS);
    

}

//This function takes in the file name selected earlier to open its respective
//roster file. This function reads the amount of lines in the selected file
//and creates a dynamic array with one less element. A second array is also
//created to copy the contents of the first array without the entry that the 
//user selected to remove.

void removeFromRoster(Player array[], int playerCount) {

    //file.open(teamName, ios::out | ios::trunc);

    //if (file.is_open()) {
    //    for (int i = 0; i < numOfPlayers-1; i++) {
    //        file << to_string(playerArray[i].getPlayerNumber()) + "," + 
    //                playerArray[i].GetName() + "," +
    //                to_string(playerArray[i].GetAge()) + "," +
    //                playerArray[i].getPlayerPOS() << endl;
    //    }
    //}
    //else { cout << "Error: File Not Open" << endl; }

    //file.close();
    //delete[] playerArray;

    //int reprintSelect;
    //do {
    //    cout << "Would you like to reprint the roster?" << endl;
    //    cout << "1.) Yes" << endl;
    //    cout << "2.) No" << endl;
    //    cin >> reprintSelect;
    //} while (reprintSelect < 1 or reprintSelect > 2);

    //if(reprintSelect == 1)
    //    printRoster(teamName);

    //rosterOptions(teamName);
}

#endif // !ROSTERS_CPP
