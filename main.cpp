#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "player.h"
#include "rosters.cpp"

using namespace std;

void printBucsRoster();
void printSaintsRoster();

int main(){
    int selection;
    int loopControl;
    do {
        cout << "What roster do you want to do?" << endl;
        cout << "1.) Print Buccaneers Roster" << endl;
        cout << "2.) Print Saints Roster" << endl;
        cout << "3.) Add to Buccaneers Roster" << endl;
        cin >> selection;

        switch (selection) {

        case 1:
            printBucsRoster();
            break;

        case 2:
            printSaintsRoster();
            break;

        case 3:
            addToBucsRoster();
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


