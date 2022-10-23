//Austin Layne
//Nathaniel Moreno

#include "linearSearch.h"

TeamRecord* linearSearchWins(TeamRecord* recordArray, int& size, int amount) {
    cout << endl;
    cout << setfill(' ') << setw(10) << " " << "Team"
        << setfill(' ') << setw(15) << " " << "Wins"
        << setfill(' ') << setw(7) << " " << "Losses"
        << setfill(' ') << setw(5) << " " << "Ties"
        << setfill(' ') << setw(5) << " " << "Percentage" << endl;
    cout << endl;

    int flag = 0;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < size; i++) {
        cout << left;
        if (recordArray[i].win == amount) {
            cout << setw(30) << recordArray[i].teamName << " "
                << setw(10) << recordArray[i].win << " "
                << setw(10) << recordArray[i].loss << " "
                << setw(10) << recordArray[i].tie << " "
                << setw(2) << fixed << setprecision(0) << right
                << recordArray[i].percentage << endl;
            flag = 1;
        }
    }
    auto end = chrono::steady_clock::now();
    if (flag == 0) {
        cout << "No results found." << endl;
    }
    double elapsedTime = double(::chrono::duration_cast <::chrono::milliseconds> (end - start).count());
    cout << "Elapsed Time: " << elapsedTime << " milliseconds." << endl;
    return recordArray;
}

TeamRecord* linearSearchLosses(TeamRecord* recordArray, int& size, int amount) {
    cout << endl;
    cout << setfill(' ') << setw(10) << " " << "Team"
        << setfill(' ') << setw(15) << " " << "Wins"
        << setfill(' ') << setw(7) << " " << "Losses"
        << setfill(' ') << setw(5) << " " << "Ties"
        << setfill(' ') << setw(5) << " " << "Percentage" << endl;
    cout << endl;

    int flag = 0;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < size; i++) {
        cout << left;
        if (recordArray[i].loss == amount) {
            cout << setw(30) << recordArray[i].teamName << " "
                << setw(10) << recordArray[i].win << " "
                << setw(10) << recordArray[i].loss << " "
                << setw(10) << recordArray[i].tie << " "
                << setw(2) << fixed << setprecision(0) << right
                << recordArray[i].percentage << endl;
            flag = 1;
        }
    }
    auto end = chrono::steady_clock::now();
    if (flag == 0) {
        cout << "No results found." << endl;
    }
    double elapsedTime = double(::chrono::duration_cast <::chrono::milliseconds> (end - start).count());
    cout << "Elapsed Time: " << elapsedTime << " milliseconds." << endl;
    return recordArray;
}

TeamRecord* linearSearchTies(TeamRecord* recordArray, int& size, int amount) {
    cout << endl;
    cout << setfill(' ') << setw(10) << " " << "Team"
        << setfill(' ') << setw(15) << " " << "Wins"
        << setfill(' ') << setw(7) << " " << "Losses"
        << setfill(' ') << setw(5) << " " << "Ties"
        << setfill(' ') << setw(5) << " " << "Percentage" << endl;
    cout << endl;

    int flag = 0;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < size; i++) {
        cout << left;
        if (recordArray[i].tie == amount) {
            cout << setw(30) << recordArray[i].teamName << " "
                << setw(10) << recordArray[i].win << " "
                << setw(10) << recordArray[i].loss << " "
                << setw(10) << recordArray[i].tie << " "
                << setw(2) << fixed << setprecision(0) << right
                << recordArray[i].percentage << endl;
            flag = 1;
        }
    }
    auto end = chrono::steady_clock::now();
    if (flag == 0) {
        cout << "No results found." << endl;
    }
    double elapsedTime = double(::chrono::duration_cast <::chrono::milliseconds> (end - start).count());
    cout << "Elapsed Time: " << elapsedTime << " milliseconds." << endl;
    return recordArray;
}