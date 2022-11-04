#include <iostream>
#include <fstream>
#include <sstream>
#include "PlayerList.h"
#include "main.cpp"         //comment out for windows.
#include "mainmenu.cpp"     //comment out for windows.
using namespace std;

void mainMenu();
PlayerList* createList(PlayerList* list, string teamName);
PlayerList* addToList(PlayerList* list, string teamName);
PlayerList* deleteFromList(PlayerList* list, string teamName);

void listTest() {
	cout << "Testing in listTest file." << endl;

        int teamSelect;
    string teamName;

    cout << "What team would you like to view?" << endl;
    cout << "1.) Tampa Bay Buccaneers" << endl;
    cout << "2.) New Orleans Saints" << endl;
    cin >> teamSelect;
    cin.ignore();

    switch (teamSelect)
    {
    case 1:
        teamName = "buccaneers.txt";
        break;

    case 2:
        teamName = "saints.txt";
    
    default:
        break;
    }

    //cout << "Will now enter creatList() function." << endl;
    //system("pause");
    PlayerList* list1 = new PlayerList;
    list1 = createList(list1, teamName);
    list1->displayList();

    int menuSelect;
    cout << "What do you want to do?" << endl;
    cout << "1.) Add Player" << endl;
    cout << "2.) Remove Player" << endl;
    cout << "3.) Return to Main Menu" << endl;
    cin >> menuSelect;
    cin.ignore();

    switch(menuSelect){
        case 1:
            list1 = addToList(list1, teamName);
            listTest();
            break;
        
        case 2:
            list1 = deleteFromList(list1, teamName);
            listTest();
            break;

        case 3:
            mainMenu();
    }
    //list1 = addToList(list1);    
    //list1 = deleteFromList(list1);    

    // system("pause");
}


/*****************************************************************************/
/*****************************************************************************/
PlayerList* createList(PlayerList* list, string teamName) {
    //declaring integer counter for number of lines in input file
    int size = 0;

    fstream file(teamName);
    string playerNumber, playerName, playerAge, playerPOS, tempData;
    string line;

    file.close();
    file.open(teamName);

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

        list->insertNode(number, playerName, age, playerPOS);
    }

    return list;
}

PlayerList* addToList(PlayerList* list, string teamName) {
    string playerName, playerPOS;
    int playerNum, playerAge;
    cout << "In addToList() Function" << endl;
    cout << "What is the player's name?" << endl;
    getline(cin, playerName);
    cin.ignore();
    cout << "What is the player's number?" << endl;
    cin >> playerNum;
    cout << "What is the player's age?" << endl;
    cin >> playerAge;
    cout << "What is the player's position?" << endl;
    cin >> playerPOS;

    list->insertNode(playerNum, playerName, playerAge, playerPOS);
    list->displayList();
    list->writeListToFile(teamName);

    return list;
}

PlayerList* deleteFromList(PlayerList* list, string teamName) {
    int numToDelete;

    cout << "Typer the number of the player to delete." << endl;
    cin >> numToDelete;

    list->deleteNode(numToDelete);

    cout << "New list will now be displayed." << endl;
    system("pause");
    list->displayList();
    list->writeListToFile(teamName);

    return list;
}


