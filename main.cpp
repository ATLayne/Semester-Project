#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "player.h"

using namespace std;

void bucsRoster();
void saintsRoster();

int main(){
    int selection;
    int loopControl;
    do {
        cout << "What roster do you want to see?" << endl;
        cout << "1.) Buccaneers" << endl;
        cout << "2.) Saints" << endl;
        cin >> selection;

        switch (selection) {

        case 1:
            bucsRoster();
            break;

        case 2:
            saintsRoster();
            break;

        default:
            cout << "Invalid Choice" << endl;
        }

        cout << "Press 1 to continue, else press any key." << endl;
        cin >> loopControl;
        system("cls");
    } while (loopControl == 1);
    return 0;
}


void bucsRoster() {
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
        playerArray[i].display();
    }

    file.close();
    delete[] playerArray;
}

void saintsRoster() {
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
