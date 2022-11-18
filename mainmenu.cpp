//Austin Layne
//Nathaniel Moreno


#ifndef MAINMENU_CPP
#define MAINMENU_CPP
#include <stdlib.h>
#include <iostream>
//#include "listTest.cpp"     //comment out for windows
//#include "rostermenus.cpp"
//#include "teamMenu.cpp"
using namespace std;

//Serves as a starting point for users of the program.
//simple switch statement used to call other functions 
//included in the program.
void rosterSelection();
void teamRecordMenu();
void listTest();

void mainMenu() {
    system("cls");
    cin.clear();
    int selection = 0;

        cout << "*****MAIN MENU*****\n\n";
        cout << "What do you want to do?" << endl;
        cout << "1.) Open Roster Menu" << endl;
        cout << "2.) Open Team Record Menu" << endl;
        cout << "3.) ---Quit Program---" << endl;
        cin >> selection;
        cin.ignore();

        switch (selection) {

            case 1:
                //rosterSelection();
                listTest();
                break;

            case 2:
                teamRecordMenu();
                break;

            case 3:
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
