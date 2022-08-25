#ifndef EXPLOREROSTERS_CPP
#define EXPLOREROSTERS_CPP

#include "rosters.cpp"

void mainMenu();
void rosterMenu(string teamSelect);
void exploreRosters(){
    system("cls");
    int selection1=0;
    string teamSelect;
	cout << "What team roster would you like to view?" << endl;
	cout << "1.) Tampa Bay Buccaneers" << endl;
	cout << "2.) New Orleans Saints" << endl;
    cout << "3.) ---Return to Main Menu---" << endl;
	cin >> selection1;

    //If statements to set the name of the file to be passed to future functions.
    if (selection1 == 1)
        teamSelect = "buccaneers.txt";
    if (selection1 == 2)
        teamSelect = "saints.txt";
    if (selection1 == 3)
        mainMenu();

    rosterMenu(teamSelect);
}

void rosterMenu(string teamSelect) {
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
        removeFromRoster(teamSelect);
        break;

    case 4:
        exploreRosters();
        break;

    default:
        cout << "Invalid Choice" << endl;
    }
    rosterMenu(teamSelect);
}

#endif // !EXPLOREROSTERS_CPP
