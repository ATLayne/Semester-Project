//Austin Layne
//Nathaniel Moreno


#ifndef ROSTERMENUS_CPP
#define ROSTERMENUS_CPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "player.h"
using namespace std;

void mainMenu();
void rosterSelection();
Player* createPlayerArray(string teamName, int&size);
Player* rosterOptions(Player* playrArray, int& size, string teamName);
Player* printRoster(Player* playerArray, int& size);
Player* addToRoster(Player* playerArray, int& size);
Player* removeFromRoster(Player* playerArray, int& size);
void writeToFile(Player* playerArray, int& size, string teamName);

void rosterSelection() {
    system("cls");
    int selection1 = 0;
    string teamSelect;

    do {
        cout << "What team roster would you like to view?" << endl;
        cout << "1.) Tampa Bay Buccaneers" << endl;
        cout << "2.) New Orleans Saints" << endl;
        cout << "3.) ---Return to Main Menu---" << endl;
        cin >> selection1;
        if (selection1 < 1 or selection1 > 3) {
            cout << "Invalid Choice" << endl;
        }
    } while (selection1 < 1 or selection1 > 3);

    //If statements to set the name of the file to be passed to future functions.
    if (selection1 == 1)
        teamSelect = "buccaneers.txt";
    if (selection1 == 2)
        teamSelect = "saints.txt";
    if (selection1 == 3)
        mainMenu();
    int size;
    Player* playerArray = createPlayerArray(teamSelect, size);
    playerArray = rosterOptions(playerArray, size, teamSelect);
}

Player* createPlayerArray(string teamName, int& size) {
    system("cls");
    cout << "In createPlayerArray function" << endl;
    cout << teamName << "\n" << endl;

    //declaring integer counter for number of lines in input file
    size = 0;

    fstream file(teamName);
    string playerNumber, playerName, playerAge, playerPOS, tempData;
    string line;

    // count the number of players
    while (getline(file, line)) {
        size += 1;
    }

    //Creating the dynamic array of Player objects
    Player* tempArray = new Player[size];

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

        tempArray[i].setPlayerInfo(playerName, number, age, playerPOS);
        i++;
    }

    cout << "Created Roster Array." << endl;
    system("pause");
    return tempArray;
}

Player* rosterOptions(Player* playerArray, int& size, string teamName) {
    int selection = 0;

    cout << "Would you like to Print or Edit" << endl;
    cout << "1.) Print" << endl;
    cout << "2.) Add To Roster" << endl;
    cout << "3.) Remove From Roster" << endl;
    cout << "4.) ---Go Back---" << endl;
    cin >> selection;

    switch (selection) {

    case 1:
        playerArray = printRoster(playerArray, size);
        rosterOptions(playerArray, size, teamName);
        break;

    case 2:
        playerArray = addToRoster(playerArray, size);
        writeToFile(playerArray, size, teamName);
        rosterOptions(playerArray, size, teamName);
        break;

    case 3:
        playerArray = removeFromRoster(playerArray, size);
        writeToFile(playerArray, size, teamName);
        rosterOptions(playerArray, size, teamName);
        break;

    case 4:
        delete[] playerArray;
        rosterSelection();
        break;

    default:
        cout << "Invalid Choice" << endl;
    }
    return playerArray;
}

Player* printRoster(Player* playerArray, int& size) {
    int outputCounter = 0;
    int outputControl = 19;
    for (int i = 0; i < size; i++) {
        if (i % 20 == 0) {
            cout << endl;
            cout << setfill(' ') << setw(10) << " " << "Name"
                << setfill(' ') << setw(12) << " " << "Number"
                << setfill(' ') << setw(12) << " " << "Age"
                << setfill(' ') << setw(4) << " " << "Position" << endl;
            cout << endl;
        }

        int counter = i + 1;
        cout << right;
        cout << setw(2) << counter << ".) ";
        playerArray[i].display();

        if (outputCounter == outputControl) {
            system("pause");
            outputControl += 20;
        }
        outputCounter++;
    }
    system("pause");
    return playerArray;
}

Player* addToRoster(Player* playerArray, int& size) {
    cout << "Called add to roster function" << endl;
    int addNumber, addAge;
    string addName, addPOS;
    char continueSelect;
    fstream file;
    cin.ignore();

    cout << "What is the players name?" << endl;
    getline(cin, addName);
    cout << "What is the players number?" << endl;
    cin >> addNumber;
    cin.ignore();
    cout << "What is the players age?" << endl;
    cin >> addAge;
    cin.ignore();
    cout << "What is the players Position?" << endl;
    cin.ignore();
    getline(cin, addPOS);
    size++;
    Player* tempArray = new Player[size];

    for (int i = 0; i < size-1; i++) {
        tempArray[i].setPlayerInfo(
            playerArray[i].getPlayerName(),
            playerArray[i].getPlayerNumber(),
            playerArray[i].GetAge(),
            playerArray[i].getPlayerPOS()
            );
    }
    tempArray[size-1].setPlayerInfo(addName, addNumber, addAge, addPOS);

    delete[] playerArray;
    playerArray = tempArray;

    return playerArray;
}

Player* removeFromRoster(Player* playerArray, int& size) {
    cout << "A roster will now be printed to allow selection." << endl;
    playerArray = printRoster(playerArray, size);

    cout << "Please select the number next to the player you would like to delete." << endl;
    int index;
    cin >> index;
    index--;

    size--;
    Player* tempArray = new Player[size];

    for (int i = 0; i < index; i++) {
        tempArray[i].setPlayerInfo(
            playerArray[i].getPlayerName(),
            playerArray[i].getPlayerNumber(),
            playerArray[i].GetAge(),
            playerArray[i].getPlayerPOS()
            );
    }

    for (int i = index; i < size; i++) {
        tempArray[i].setPlayerInfo(
            playerArray[i+1].getPlayerName(),
            playerArray[i+1].getPlayerNumber(),
            playerArray[i+1].GetAge(),
            playerArray[i+1].getPlayerPOS()
            );
    }
    delete[] playerArray;
    playerArray = tempArray;
    
    return playerArray;
}

void writeToFile(Player* playerArray, int& size, string teamName) {
    cout << "Called write to file function." << endl;
    fstream file;
    file.open(teamName, ios::out | ios::trunc);

    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            file << to_string(playerArray[i].getPlayerNumber()) + "," +
                playerArray[i].GetName() + "," +
                to_string(playerArray[i].GetAge()) + "," +
                playerArray[i].getPlayerPOS() << endl;
        }
    }
    else { cout << "error: file not open" << endl; }

    file.close();
}

#endif // !ROSTERMENUS_H
