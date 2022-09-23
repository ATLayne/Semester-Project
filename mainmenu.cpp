//Austin Layne
//Nathaniel Moreno


#ifndef MAINMENU_CPP
#define MAINMENU_CPP
#include <stdlib.h>
#include <iostream>
#include "rostermenus.cpp"

using namespace std;


//Serves as a starting point for users of the program.
//simple switch statement used to call other functions 
//included in the program.
void exploreRosters();

void mainMenu() {
    system("cls");
    cin.clear();
    int selection = 0;

        cout << "*****MAIN MENU*****\n\n";
        cout << "What do you want to do?" << endl;
        cout << "1.) Explore Rosters" << endl;
        cout << "2.) ---Quit Program---" << endl;
        cin >> selection;

        switch (selection) {

            case 1:
                exploreRosters();
                break;

            case 2:
                exit(1);
                break;

            default:
                cout << "Invalid Choice" << endl;
                system("pause");
                mainMenu();
                break;
        }
}


#endif
