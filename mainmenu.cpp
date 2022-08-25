#ifndef MAINMENU_CPP
#define MAINMENU_CPP
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "player.h"
#include "rosters.cpp"
#include "exploreRosters.cpp"

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
                break;

            default:
                cout << "Invalid Choice" << endl;
                system("pause");
                mainMenu();
                break;
        }
}


#endif