#ifndef LISTTEST_CPP
#define LISTTEST_CPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include "PlayerList.h"
//#include "main.cpp"         //comment out for windows.
//#include "mainmenu.cpp"     //comment out for windows.
using namespace std;

void mainMenu();
PlayerList* createList(PlayerList* list, string teamName);
void selectedRosterMenu(PlayerList* list, string teamName);
PlayerList* addToList(PlayerList* list, string teamName);
PlayerList* deleteFromList(PlayerList* list, string teamName);
void searchList(PlayerList* list);

void listTest() {
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

    PlayerList* list1 = new PlayerList;
    list1 = createList(list1, teamName);
    selectedRosterMenu(list1, teamName);
}

void selectedRosterMenu(PlayerList* list, string teamName){
    int menuSelect;
    cout << "What do you want to do?" << endl;
    cout << "1.) Print Roster" << endl;
    cout << "2.) Add Player" << endl;
    cout << "3.) Remove Player" << endl;
    cout << "4.) Search Roster" << endl;
    cout << "5.) Return to Main Menu" << endl;
    cin >> menuSelect;
    cin.ignore();

    switch(menuSelect){
        case 1:
            list->displayList();
            selectedRosterMenu(list, teamName);
            break;

        case 2:
            list = addToList(list, teamName);
            selectedRosterMenu(list, teamName);
            break;
        
        case 3:
            list = deleteFromList(list, teamName);
            selectedRosterMenu(list, teamName);
            break;

        case 4:
            searchList(list);
            selectedRosterMenu(list, teamName);
            break;

        case 5:
            mainMenu();
    }
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
    bool validInput = true;
    string playerName, playerPOS;
    int playerNum, playerAge;
    cout << "In addToList() Function" << endl;
    cout << "What is the player's name?" << endl;
    getline(cin, playerName);
    cin.ignore();

    do{
    validInput = true;
    cout << "What is the player's number?" << endl;
    cin >> playerNum;
        if(playerNum < 0 or playerNum > 99){
            cout << "Please enter a valid number (0-99)" << endl;
            validInput = false;
        }
    } while(validInput == false);

    do{
    validInput = true;
    cout << "What is the player's age?" << endl;
    cin >> playerAge;
        if(playerAge < 0 or playerAge > 99){
            cout << "Please enter a valid number (0-99)" << endl;
            validInput = false;
        }
    } while (validInput == false);
    
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

void searchList(PlayerList* list){
    int numToSearch;
    cout << "What player number would you like to search for?" << endl;
    cin >> numToSearch;

    auto start = chrono::steady_clock::now();
    list->searchList(numToSearch);
    auto end = chrono::steady_clock::now();
    double elapsedTime = double(::chrono::duration_cast <::chrono::microseconds> 
        (end - start).count());
    cout << "Elapsed Time: " << elapsedTime << " microseconds." << endl;
}

#endif
