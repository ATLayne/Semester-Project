//Nathaniel Moreno

#ifndef QBSTATSMENU_CPP
#define QBSTATSMENU_CPP

// This Program file to read in a text file that contains QB Stats
// An array of QBstats structs will be created to display to the
// user. The should User will then be able to update QB stats.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include "QBstats.h"
#include "linearSearch.h"
using namespace std;

void QBstatsMenu();
QBstats* createStatsArray(int& size);
QBstats* printQBstats(QBstats* StatsArray, int& size);
QBstats* editQBstats(QBstats* StatsArray, int& size);
QBstats* searchQBstats(QBstats* StatsArray, int& size);
QBstats* sortQBstats(QBstats* StatsArray, int& size);

QBstats* selectionSortAscendingPassing(QBstats* StatsArray, int& size);
QBstats* selectionSortDescendingPassing(QBstats* StatsArray, int& size);
QBstats* selectionSortAscendingTouchdowns(QBstats* StatsArray, int& size);
QBstats* selectionSortDescendingTouchdowns(QBstats* StatsArray, int& size);
QBstats* selectionSortAscendingInts(QBstats* StatsArray, int& size);
QBstats* selectionSortDescendingInts(QBstats* StatsArray, int& size);
void mainMenu();

void QBstatsMenu(){ 
  int size;
  QBstats* StatsArray = createStatsArray(size);

  int selection; //User Input
   cout << "What would you like to do?" << endl;
    cout << "1.) Print QB Stats" << endl;
    cout << "2.) Search QB Stats" << endl;
    cout << "3.) Sort QB Stats" << endl;
    cout << "4.) Return to Main Menu." << endl;
    cin >> selection;
    cin.ignore();

   switch (selection){
        case 1:
            StatsArray = printQBstats(StatsArray, size); //Displays 
            break;

        case 2:
            StatsArray = searchQBstats(StatsArray, size);
            break;

        case 3:
            StatsArray = sortQBstats(StatsArray, size);
            break;

        case 4:
            delete[] StatsArray;
            mainMenu();
            break;
        
        default:
            cout << "Invalid Choice. Please select again." << endl;
            system("pause");
            QBstatsMenu();
            break;
    }
   QBstatsMenu();
}

// ***Grabs the data from the text file***
QBstats* createStatsArray(int& size) {
    system("cls");

    //declaring integer counter for number of lines in input file
    size = 0;

    fstream file("QBstats.txt"); //File for QB Data
    string QBName, Passing, Touchdowns, Ints, tempData;
    string line;


    // count the number of QBs
    while (getline(file, line)){
        size += 1;
    }
   QBstats* StatsArray = new QBstats[size];

    file.close();
    file.open("QBstats.txt");

  //Each line is read through the file to set the data
  //members of the struct.
    int i = 0;
    int PassingInput, TouchdownsInput, IntsInput;
    while (getline(file, line)) {

        stringstream ss(line);
        getline(ss, QBName, ',');
        getline(ss, Passing, ',');
        getline(ss, Touchdowns, ',');
        getline(ss, Ints, ',');
        getline(ss, tempData, '\n');

        PassingInput = stoi(Passing);
        TouchdownsInput = stoi(Touchdowns);
        IntsInput = stoi(Ints);

        StatsArray[i].QBName = QBName;
        StatsArray[i].Passing = PassingInput;
        StatsArray[i].Touchdowns = TouchdownsInput;
        StatsArray[i].Ints = IntsInput;
        //StatsArray[i].percentage = (StatsArray[i].Passing / 
                                    //(StatsArray[i].Passing + 
                                     //StatsArray[i].Touchdowns + 
                                    // StatsArray[i].Ints))*100;

        i++;
    }
    file.close();
    return StatsArray;
}

//***This function displays the data from file 
//using the members of the struct*** 
QBstats* printQBstats(QBstats* StatsArray, int& size) {
  
    int outputCounter = 0;
    int outputControl = 15;
    for (int i = 0; i < size; i++) {
        if (i%16 == 0) {
            cout << endl;
            cout << setfill(' ') << setw(10) << " " << "QB Name" 
                << setfill(' ') << setw(18) << " " << "Passing"
                << setfill(' ') << setw(5) << " " << "Touchdowns"
                << setfill(' ') << setw(3) << " " << "Ints" << endl;
              
                //<< setfill(' ') << setw(5)  << " " << "Passer Rating" << endl;
            cout << endl;
        }

        int counter = i + 1;
        cout << left;
        cout << setw(2) << counter  << ".) ";
        cout << setw(30) << StatsArray[i].QBName << " "
            << setw(10) << StatsArray[i].Passing << " "
            << setw(10) << StatsArray[i].Touchdowns << " "
            << setw(10) << StatsArray[i].Ints << " " << endl;

        if (outputCounter == outputControl) { 
            system("pause");
            outputControl += 16;
        }
        outputCounter++;
    }

    //User gets to choose whether or not to edit
    //a QBs stat.
    char StatEditSelection; //User selection
    cout << "Would you like to edit a Stat? Y/N" << endl;
    cin >> StatEditSelection;

    if (StatEditSelection == 'Y' or StatEditSelection == 'y')
        editQBstats(StatsArray, size);

    system("pause");
    return StatsArray; //User is returned to menu
}

//***This function is made to edit the stats(elements) 
//of the QBstats array***
QBstats* editQBstats(QBstats*  StatsArray, int& size){
    int QBSelect;  //User Input for QB
    int statSelect; //User Input for stat
    cout << "Type the number of the QB to select it." << endl;
    cin >> QBSelect;
    QBSelect--;
    cout << "Do you want to edit Passing yards, Touchdowns, or Ints?" << endl;
    cout << "1.) Passing" << endl
         << "2.) Touchdowns" << endl
         << "3.) Ints" << endl;
    cin >> statSelect; 
    
    int statEdit = 0;
    switch (statSelect) {
        case 1:
            cout << "How many Passing yards does " +  StatsArray[QBSelect].QBName +
                " have?" << endl;
            cin >> statEdit;
            while (cin.fail()) {
                cout << "Please enter an valid number." << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> statEdit;
            }
             StatsArray[QBSelect].Passing = statEdit;
            cout << endl;
            break;

        case 2:
            cout << "How many Touchdowns does " +  StatsArray[QBSelect].QBName +
                " have?" << endl;
            cin >> statEdit;
            while (cin.fail()) {
                cout << "Please enter an valid number." << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> statEdit;
            }
             StatsArray[QBSelect].Touchdowns = statEdit;
            cout << endl;
            break;

        case 3:
            cout << "How many Ints does " +  StatsArray[QBSelect].QBName +
                " have?" << endl;
            cin >> statEdit;
            while (cin.fail()) {
                cout << "Please enter an valid number." << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> statEdit;
            }
             StatsArray[QBSelect].Ints = statEdit;
            cout << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
            editQBstats( StatsArray, size);
    }

    fstream file("QBstats.txt"); 
    int count = 0;
    string line;
    while (getline(file, line)){
        count += 1;
    }

    file.close();
    file.open("QBstats.txt", ios::out | ios::trunc); //File is written to
        if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            file <<  StatsArray[i].QBName + "," +
                    to_string( StatsArray[i].Passing) + "," +
                    to_string( StatsArray[i].Touchdowns) + "," +
                    to_string( StatsArray[i].Ints) + "," +  
                    to_string( StatsArray[i].percentage) << endl;
        }
    }
    else { cout << "Error: File Not Open" << endl; }
    file.close();

    return  StatsArray; //User returned to Menu
}

//***This function is made to let the user decide what
//QB stat they want to search for***
QBstats* searchQBstats(QBstats* StatsArray, int& size) {
    int selection, amountToDisplay;
    cout << "Search For: " << endl;
    cout << "1.) Passing yards" << endl;
    cout << "2.) Toucdowns" << endl;
    cout << "3.) Ints" << endl;
    cin >> selection;

    switch (selection) {
        case 1:
            cout << "QBs with how many Passing yards should be displayed?" << endl;
            cin >> amountToDisplay;
            StatsArray = linearSearchPassing(StatsArray, size, amountToDisplay);
            system("pause");
            QBstatsMenu();
            break;
        case 2:
            cout << "QBs with how many Touchdowns should be displayed?" << endl;
            cin >> amountToDisplay;
            StatsArray = linearSearchTouchdowns(StatsArray, size, amountToDisplay);
            system("pause");
            break;
        case 3:
            cout << "QBs with how many Ints should be displayed?" << endl;
            cin >> amountToDisplay;
            StatsArray = linearSearchInts(StatsArray, size, amountToDisplay);
            system("pause");
            break;
    }
    return StatsArray; //Returned to Menu
}

//***This function is made to let the user decide how to 
//sort the stats of the choosen QB***
QBstats* sortQBstats(QBstats* StatsArray, int& size) {
    cout << "Sort by:" << endl;
    cout << "1.) Passing yards" << endl;
    cout << "2.) Touchdowns" << endl;
    cout << "3.) Ints" << endl;
    int selection;
    cin >> selection;

    switch (selection)
    {
        int selection2;
        case 1:
            cout << "What Order?" << endl;
            cout << "1.) Ascending" << endl;
            cout << "2.) Descending" << endl;
            cin >> selection2;
            if (selection2 == 1) {
                StatsArray = selectionSortAscendingPassing(StatsArray, size);
            }
            else if (selection2 == 2) {
                StatsArray = selectionSortDescendingPassing(StatsArray, size);
            }
            break;

        case 2:
            cout << "What Order?" << endl;
            cout << "1.) Ascending" << endl;
            cout << "2.) Descending" << endl;
            cin >> selection2;
            if (selection2 == 1) {
                StatsArray = selectionSortAscendingTouchdowns(StatsArray, size);
            }
            else if (selection2 == 2) {
                StatsArray = selectionSortDescendingTouchdowns(StatsArray, size);
            }
            break;
        default:
            break;
    }
    return StatsArray;
}
//***Sorting Algorithm for Passing yards***
  QBstats* selectionSortAscendingPassing(QBstats* StatsArray, int& size) {
    int i, j, indexSmallest;
    auto start = chrono::steady_clock::now();   //begin the timer
    for (i = 0; i < size - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
            for (j = i + 1; j < size; ++j) {

                if (StatsArray[j].Passing < StatsArray[indexSmallest].Passing) {
                    indexSmallest = j;
                }
            }

        // Swap numbers[i] and numbers[indexSmallest]
        QBstats temp;
        temp = StatsArray[i];
        StatsArray[i] = StatsArray[indexSmallest];
        StatsArray[indexSmallest] = temp;
    }
    auto end = chrono::steady_clock::now();     //end timer after sorting loop completes
    double elapsedTime = double(::chrono::duration_cast <::chrono::microseconds> 
                         (end - start).count());
    StatsArray = printQBstats(StatsArray, size);
    cout << "Elapsed Time: " << elapsedTime << " microseconds." << endl;
    system("pause");
    return StatsArray;
}

QBstats* selectionSortDescendingPassing(QBstats* StatsArray, int& size) {
    int i, j, indexSmallest;
    auto start = chrono::steady_clock::now();
    for (i = 0; i < size - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < size; ++j) {

            if (StatsArray[j].Passing > StatsArray[indexSmallest].Passing) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        QBstats temp;
        temp = StatsArray[i];
        StatsArray[i] = StatsArray[indexSmallest];
        StatsArray[indexSmallest] = temp;
    }
    auto end = chrono::steady_clock::now();
    double elapsedTime = double(::chrono::duration_cast <::chrono::microseconds> 
                         (end - start).count());
    StatsArray = printQBstats(StatsArray, size);
    cout << "Elapsed Time: " << elapsedTime << " microseconds." << endl;
    system("pause");
    return StatsArray;
}

  //***Sorting algorithm for Touchdowns***
  QBstats* selectionSortAscendingTouchdowns(QBstats* StatsArray, int& size) {
    int i, j, indexSmallest;
    auto start = chrono::steady_clock::now();
    for (i = 0; i < size - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < size; ++j) {

            if (StatsArray[j].Touchdowns < StatsArray[indexSmallest].Touchdowns) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        QBstats temp;
        temp = StatsArray[i];
        StatsArray[i] = StatsArray[indexSmallest];
        StatsArray[indexSmallest] = temp;
    }
    auto end = chrono::steady_clock::now();
    double elapsedTime = double(::chrono::duration_cast <::chrono::microseconds> 
                         (end - start).count());
    StatsArray = printQBstats(StatsArray, size);
    cout << "Elapsed Time: " << elapsedTime << " microseconds." << endl;
    system("pause");
    return StatsArray;
}

QBstats* selectionSortDescendingTouchdowns(QBstats* StatsArray, int& size) {
    int i, j, indexSmallest;
    auto start = chrono::steady_clock::now();
    for (i = 0; i < size - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < size; ++j) {

            if (StatsArray[j].Touchdowns > StatsArray[indexSmallest].Touchdowns) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        QBstats temp;
        temp = StatsArray[i];
        StatsArray[i] = StatsArray[indexSmallest];
        StatsArray[indexSmallest] = temp;
    }
    auto end = chrono::steady_clock::now();
    double elapsedTime = double(::chrono::duration_cast <::chrono::microseconds> 
                         (end - start).count());
    StatsArray = printQBstats(StatsArray, size);
    cout << "Elapsed Time: " << elapsedTime << " microseconds." << endl;
    system("pause");
    return StatsArray;
}

//***Sorting algorithm for Ints***
QBstats* selectionSortAscendingInts(QBstats* StatsArray, int& size) {
    int i, j, indexSmallest;
    auto start = chrono::steady_clock::now();
    for (i = 0; i < size - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < size; ++j) {

            if (StatsArray[j].Ints < StatsArray[indexSmallest].Ints) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        QBstats temp;
        temp = StatsArray[i];
        StatsArray[i] = StatsArray[indexSmallest];
        StatsArray[indexSmallest] = temp;
    }
    auto end = chrono::steady_clock::now();
    double elapsedTime = double(::chrono::duration_cast <::chrono::microseconds> 
                         (end - start).count());
    StatsArray = printQBstats(StatsArray, size);
    cout << "Elapsed Time: " << elapsedTime << " microseconds." << endl;
    system("pause");
    return StatsArray;
}

QBstats* selectionSortDescendingInts(QBstats* StatsArray, int& size) {
    int i, j, indexSmallest;
    auto start = chrono::steady_clock::now();
    for (i = 0; i < size - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < size; ++j) {

            if (StatsArray[j].Ints > StatsArray[indexSmallest].Ints) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        QBstats temp;
        temp = StatsArray[i];
        StatsArray[i] = StatsArray[indexSmallest];
        StatsArray[indexSmallest] = temp;
    }
    auto end = chrono::steady_clock::now();
    double elapsedTime = double(::chrono::duration_cast <::chrono::microseconds> 
                         (end - start).count());
    StatsArray = printQBstats(StatsArray, size);
    cout << "Elapsed Time: " << elapsedTime << " microseconds." << endl;
    system("pause");
    return StatsArray;
}
#endif