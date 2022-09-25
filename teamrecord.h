// File that creates a struct for TeamRecord.
// TeamRecord holds win/loss/tie data on each
// team.

#ifndef TEAMRECORD_H
#define TEAMRECORD_H
#include <iostream>
#include <string>
using namespace std;

struct TeamRecord
{
    string teamName;
    int win, loss, tie;
};


#endif
