//Austin Layne
//Nathaniel Moreno


#ifndef ROSTERS_CPP
#define ROSTERS_CPP

#include "player.h"

void rosterMenu(string teamName);


//This function takes in the file name selected earlier to open its respective
//roster file. This function creates a dynamic array with the contents of the file
//and calls the display function defined in the header file.

void printRoster(string teamName) {
    system("cls");
    cout << teamName << "\n" << endl;

    //declaring integer counter for number of lines in input file
    int numOfPlayers = 0;

    fstream file(teamName);
    string playerNumber, playerName, playerPOS, tempData;
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
        getline(ss, playerPOS, ',');
        getline(ss, tempData, ',');

        if (playerNumber == "") {
            number = 0;
        }
        else {
            number = stoi(playerNumber);
        }

        playerArray[i].setPlayerInfo(playerName, number, playerPOS);
        i++;
    }

    int outputCounter = 0;
    int outputControl = 19;
    for (int i = 0; i < numOfPlayers; i++) {
        if (i%20 == 0) {
            cout << endl;
            cout << setfill(' ') << setw(10) << " " << "Name" 
                 << setfill(' ') << setw(12) << " " << "Number" 
                 << setfill(' ') << setw(4)  << " " << "Position" << endl;
            cout << endl;
        }

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

//This function takes in the file name selected earlier to open its respective
//roster file. This function reads the amount of lines in the selected file
//and creates a dynamic array with one extra element

void addToRoster(string teamName) {
    system("cls");

    //declaring integer counter for number of lines in input file
    int numOfPlayers = 0;
    int number, addNumber;
    string addName;
    string addPOS;

    fstream file(teamName);
    string playerNumber, playerName, playerPOS, tempData;
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
        getline(ss, playerPOS, ',');
        getline(ss, tempData, ',');

        if (playerNumber == "") {
            number = 0;
        }
        else {
            number = stoi(playerNumber);
        }

        playerArray[i].setPlayerInfo(playerName, number, playerPOS);
        i++;
    }


    do {
        cout << "What is the players number?" << endl;
        cin >> addNumber;
        cin.ignore();

        if (addNumber < 0 or addNumber > 99) {
            cout << "Invalid entry. Please enter a number between 0 and 99." << endl;
        }

    } while (addNumber < 0 or addNumber > 99);

    cout << "What is the players name?" << endl;
    getline(cin, addName); 

    cout << "What is the players Position?" << endl;
    getline(cin, addPOS);

    playerArray[numOfPlayers].setPlayerInfo(addName, addNumber, addPOS);

    file.close();
    file.open(teamName, ios::out | ios::trunc);

    if (file.is_open()) {
        for (int i = 0; i < numOfPlayers + 1; i++) {
            file << to_string(playerArray[i].getPlayerNumber()) + "," + playerArray[i].getPlayerName() + "," + playerArray[i].getPlayerPOS() << endl;
        }
    }


    file.close();
    delete[] playerArray;
    rosterMenu(teamName);
}

//This function takes in the file name selected earlier to open its respective
//roster file. This function reads the amount of lines in the selected file
//and creates a dynamic array with one less element. A second array is also
//created to copy the contents of the first array without the entry that the 
//user selected to remove.

void removeFromRoster(string teamName) {
    system("cls");

    //declaring integer counter for number of lines in input file
    int numOfPlayers = 0;

    fstream file(teamName);
    string playerNumber, playerName, playerPOS, tempData;
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
        getline(ss, playerPOS, ',');
        getline(ss, tempData, ',');

        if (playerNumber == "") {
            number = 0;
        }
        else {
            number = stoi(playerNumber);
        }

        playerArray[i].setPlayerInfo(playerName, number, playerPOS);
        i++;
    }


    file.close();
    file.open(teamName);

    printRoster(teamName);

    int index;
    do {
        cout << "Which player would you like to remove?" << endl;
        cout << "Please enter the number to the left of the name." << endl;
        cin >> index;
        cin.clear();
        if (index < 1 or index > i) {
            cout << "Invalid Entry." << endl;
        }
    } while (index < 1 or index > i);

    file.close();
    file.open(teamName);

    int j = 0;
    while (getline(file, line)) {
        if (j == index - 1) {
            break;
        }
        stringstream ss(line);
        getline(ss, playerNumber, ',');
        getline(ss, playerName, ',');
        getline(ss, playerPOS, ',');
        getline(ss, tempData, ',');

        if (playerNumber == "") {
            number = 0;
        }
        else {
            number = stoi(playerNumber);
        }

        tempArray[j].setPlayerInfo(playerName, number, playerPOS);
        j++;
    }

    int k = j;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, playerNumber, ',');
        getline(ss, playerName, ',');
        getline(ss, playerPOS, ',');
        getline(ss, tempData, ',');

        if (playerNumber == "") {
            number = 0;
        }
        else {
            number = stoi(playerNumber);
        }
        tempArray[k].setPlayerInfo(playerName, number, playerPOS);
        k++;
    }


    


    file.close();
    delete[] playerArray;
    playerArray = tempArray;


    file.open(teamName, ios::out | ios::trunc);

    if (file.is_open()) {
        for (int i = 0; i < numOfPlayers-1; i++) {
            file << to_string(playerArray[i].getPlayerNumber()) + "," + playerArray[i].getPlayerName() + "," + playerArray[i].getPlayerPOS() << endl;
        }
    }
    else { cout << "Error: File Not Open" << endl; }

    file.close();
    delete[] playerArray;

    int reprintSelect;
    do {
        cout << "Would you like to reprint the roster?" << endl;
        cout << "1.) Yes" << endl;
        cout << "2.) No" << endl;
        cin >> reprintSelect;
    } while (reprintSelect < 1 or reprintSelect > 2);

    if(reprintSelect == 1)
        printRoster(teamName);

    rosterMenu(teamName);

}

#endif // !ROSTERS_CPP
