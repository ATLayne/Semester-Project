#include <iostream>
#include <fstream>
#include <sstream>
#include "PlayerList.h"
using namespace std;

void createList();
void addToList(PlayerList list);
void deleteFromList(PlayerList list);

void listTest() {
	cout << "Testing in listTest file." << endl;

    cout << "Will now enter creatList() function." << endl;
    //system("pause");
    createList();
}


/*****************************************************************************/
/*****************************************************************************/
void createList() {
    PlayerList testList2;

    //declaring integer counter for number of lines in input file
    int size = 0;

    fstream file("buccaneers.txt");
    string playerNumber, playerName, playerAge, playerPOS, tempData;
    string line;

    //// count the number of players
    //while (getline(file, line)) {
    //    size += 1;
    //}


    file.close();
    file.open("buccaneers.txt");

    //int i = 0;
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

        testList2.insertNode(number, playerName, age, playerPOS);
    }

    testList2.displayList();
    addToList(testList2);
    system("pause");
    deleteFromList(testList2);
}

void addToList(PlayerList list) {
    string playerName, playerPOS;
    int playerNum, playerAge;
    cout << "In addToList() Function" << endl;
    cout << "What is the player's name?" << endl;
    getline(cin, playerName);
    cout << "What is the player's number?" << endl;
    cin >> playerNum;
    cout << "What is the player's age?" << endl;
    cin >> playerAge;
    cout << "What is the player's position?" << endl;
    cin >> playerPOS;

    list.insertNode(playerNum, playerName, playerAge, playerPOS);
    list.displayList();
}

void deleteFromList(PlayerList list) {
    int numToDelete;

    cout << "Typer the number of the player to delete." << endl;
    cin >> numToDelete;

    list.deleteNode(numToDelete);

    cout << "New list will now be displayed." << endl;
    system("pause");
    list.displayList();
}

