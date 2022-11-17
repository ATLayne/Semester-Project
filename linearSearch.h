//Austin Layne
//Nathaniel Moreno

#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H
#include "teamrecord.h"
#include "QBstats.h"
#include <iomanip>
#include <chrono>

TeamRecord* linearSearchWins(TeamRecord* recordArray, int& size, int amount);
TeamRecord* linearSearchLosses(TeamRecord* recordArray, int& size, int amount);
TeamRecord* linearSearchTies(TeamRecord* recordArray, int& size, int amount);
QBstats* linearSearchPassing(QBstats* StatsArray, int& size, int amount);
QBstats* linearSearchTouchdowns(QBstats* StatsArray, int& size, int amount);
QBstats* linearSearchInts(QBstats* StatsArray, int& size, int amount);


#endif // !LINEARSEARCH_H
