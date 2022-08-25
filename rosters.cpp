#ifndef ROSTERS_CPP
#define ROSTERS_CPP

#include "player.h"

void rosterMenu(string teamName);

void printRoster(string teamName) {
    system("cls");
    cout << teamName << "\n" << endl;

    //declaring integer counter for number of lines in input file
    int numOfPlayers = 0;

    fstream file(teamName);
    string playerNumber, playerName, tempData;
    string line;


    // count the number of players
    while (getline(file, line))
    {
        numOfPlayers += 1;
    }

    //Creating the dynamic array of Player objects
    Player* playerArray = new Player[numOfPlayers];

    file.close();
    file.open(teamName);

    int i = 0;
    int number;
    while (getline(file, line)) {

        stringstream ss(line);
        getline(ss, playerNumber, ',');
        getline(ss, playerName, ',');
        getline(ss, tempData, ',');

        if (playerNumber == "") {
            number = 0;
        }
        else {
            number = stoi(playerNumber);
        }

        playerArray[i].setPlayerInfo(playerName, number);
        i++;
    }

    int outputCounter = 0;
    int outputControl = 19;
    for (int i = 0; i < numOfPlayers; i++) {

        int counter = i + 1;
        cout << right;
        cout << setw(2) << counter  << ".) ";
        playerArray[i].display();

        if (outputCounter == outputControl) { 
            system("pause");
            outputControl += 20;
        }
        outputCounter++;
    }


    file.close();
    delete[] playerArray;
    system("pause");
}

void addToRoster(string teamName) {
    system("cls");

    //declaring integer counter for number of lines in input file
    int numOfPlayers = 0;
    int addNumber;
    string addName;

    fstream file(teamName);
    string playerNumber, playerName, tempData;
    string line;


    // count the number of players
    while (getline(file, line))
    {
        numOfPlayers += 1;
    }

    //Creating the dynamic array of Player objects
    Player* playerArray = new Player[numOfPlayers+1];

    file.close();
    file.open(teamName);

    int i = 0;
    while (getline(file, line)) {

        stringstream ss(line);
        getline(ss, playerNumber, ',');
        getline(ss, playerName, ',');
        getline(ss, tempData, ',');

        int number = stoi(playerNumber);

        playerArray[i].setPlayerInfo(playerName, number);
        i++;
    }

    cout << "What is the players number?" << endl;
    cin >> addNumber;
    cout << "What is the players name?" << endl;
    cin.ignore();
    getline(cin, addName);
    cin.ignore();

    playerArray[numOfPlayers].setPlayerInfo(addName, addNumber);



    //for (int i = 0; i < numOfPlayers+1; i++) {
    //    int counter = i + 1;
    //    cout << right;
    //    cout << setw(2) << counter << ".) ";
    //    playerArray[i].display();
    //}
    file.close();
    file.open(teamName);

    if (file.is_open()) {
        for (int i = 0; i < numOfPlayers + 1; i++) {
            file << to_string(playerArray[i].getPlayerNumber()) + "," + playerArray[i].getPlayerName() << endl;
        }
    }


    file.close();
    delete[] playerArray;
    rosterMenu(teamName);
}

void removeFromRoster(string teamName) {
    system("cls");

    //declaring integer counter for number of lines in input file
    int numOfPlayers = 0;

    fstream file(teamName);
    string playerNumber, playerName, tempData;
    string line;


    // count the number of players
    while (getline(file, line))
    {
        numOfPlayers += 1;
    }

    //Creating the dynamic array of Player objects
    Player* playerArray = new Player[numOfPlayers];
    Player* tempArray = new Player[numOfPlayers-1]; //creating temporary array to store objects

    file.close();
    file.open(teamName);

    int i = 0;
    int number;
    while (getline(file, line)) {

        stringstream ss(line);
        getline(ss, playerNumber, ',');
        getline(ss, playerName, ',');
        getline(ss, tempData, ',');

        if (playerNumber == "") {
            number = 0;
        }
        else {
            number = stoi(playerNumber);
        }

        playerArray[i].setPlayerInfo(playerName, number);
        i++;
    }


    file.close();
    file.open(teamName);

    printRoster(teamName);

    int index;
    cout << "Which player would you like to remove?" << endl;
    cout << "Please enter the number to the left of the name." << endl;
    cin >> index;
    cin.clear();

    file.close();
    file.open(teamName);

    int j = 0;
    while (getline(file, line)) {

        if (j != index - 1) {
            stringstream ss(line);
            getline(ss, playerNumber, ',');
            getline(ss, playerName, ',');
            getline(ss, tempData, ',');

            int number = stoi(playerNumber);

            tempArray[j].setPlayerInfo(playerName, number);
            j++;
        }
    }


    file.close();
    delete[] playerArray;
    playerArray = tempArray;


    file.open(teamName, ios::out | ios::trunc);

    if (file.is_open()) {
        for (int i = 0; i < numOfPlayers-1; i++) {
            file << to_string(playerArray[i].getPlayerNumber()) + "," + playerArray[i].getPlayerName() << endl;
        }
    }
    else { cout << "Error: File Not Open" << endl; }

    file.close();
    delete[] playerArray;

    int reprintSelect = 0;
    cout << "Would you like to reprint the roster?" << endl;
    cout << "1.) Yes" << endl;
    cout << "2.) No" << endl;
    cin >> reprintSelect;

    if(reprintSelect == 1)
        printRoster(teamName);

    rosterMenu(teamName);

}

#endif // !ROSTERS_CPP
