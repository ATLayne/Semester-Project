//Nathaniel Moreno

// File that creates a struct for QBstatsMenu.
// QBstatsMenu holds Passing yards/Touchdowns/Ints data on each QB 

#ifndef QBSTATS_H
#define QBSTATS_H
#include <iostream>
#include <string>
using namespace std;

struct QBstats 
{
    string QBName;
    double Passing = 0, Touchdowns = 0, Ints = 0;
    double percentage = 0;
};


#endif