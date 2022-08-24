#include "player.h"


void printBucsRoster() {
    //declaring integer counter for number of lines in input file
    int numOfPlayers = 0;

    fstream file("buccaneers.txt");
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
    file.open("buccaneers.txt");

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

    for (int i = 0; i < numOfPlayers; i++) {
        int counter = i + 1;
        cout << right;
        cout << setw(2) << counter  << ".) ";
        playerArray[i].display();
    }


    file.close();
    delete[] playerArray;
}

void printSaintsRoster() {
    //declaring integer counter for number of lines in input file
    int numOfPlayers = 0;

    fstream file("saints.txt");
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
    file.open("saints.txt");

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

    for (int i = 0; i < numOfPlayers; i++) {
        playerArray[i].display();
    }

    file.close();
    delete[] playerArray;
}

void addToBucsRoster() {

    //declaring integer counter for number of lines in input file
    int numOfPlayers = 0;
    int addNumber;
    string addName;

    fstream file("buccaneers.txt");
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
    file.open("buccaneers.txt");

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

    playerArray[numOfPlayers].setPlayerInfo(addName, addNumber);



    //for (int i = 0; i < numOfPlayers+1; i++) {
    //    int counter = i + 1;
    //    cout << right;
    //    cout << setw(2) << counter << ".) ";
    //    playerArray[i].display();
    //}
    file.close();
    file.open("buccaneers.txt");

    if (file.is_open()) {
        for (int i = 0; i < numOfPlayers + 1; i++) {
            file << to_string(playerArray[i].getPlayerNumber()) + "," + playerArray[i].getPlayerName() << endl;
        }
    }


    file.close();
    delete[] playerArray;
}