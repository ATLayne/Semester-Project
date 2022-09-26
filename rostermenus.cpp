//Austin Layne
//Nathaniel Moreno


#ifndef ROSTERMENUS_CPP
#define ROSTERMENUS_CPP

#include <iostream>
#include <string>
//#include "rosters.cpp"
using namespace std;

void mainMenu();
void rosterOptions(string teamSelect);
void printRoster(string teamName);
void addToRoster(string teamName);
void removeFromRoster(string teamName);

//A menu function to allow the user to select which team roster they would like to 
//manipulate.
void exploreRosters(){
    system("cls");
    int selection1=0;
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

    rosterOptions(teamSelect);
}


//Menu function to allow a user to select what operation they would like to accomplish on
//the roster they selected earlier.

void rosterOptions(string teamSelect) {

    int selection2=0;
    
    cout << "Would you like to Print or Edit" << endl;
    cout << "1.) Print" << endl;
    cout << "2.) Add To Roster" << endl;
    cout << "3.) Remove From Roster" << endl;
    cout << "4.) ---Go Back---" << endl;
    cin >> selection2;

    switch (selection2) {

    case 1:
        printRoster(teamSelect);
        break;

    case 2:
        addToRoster(teamSelect);
        break;

    case 3:
        cout << "The system will print a roster to allow selection." << endl;
        system("pause");
        removeFromRoster(teamSelect);
        break;

    case 4:
        exploreRosters();
        break;

    default:
        cout << "Invalid Choice" << endl;
    }
    rosterOptions(teamSelect);
}

#endif // !ROSTERMENUS_H
