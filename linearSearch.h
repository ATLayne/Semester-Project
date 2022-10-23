//Austin Layne
//Nathaniel Moreno

#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H
#include "teamrecord.h"
#include <iomanip>
#include <chrono>

TeamRecord* linearSearchWins(TeamRecord* recordArray, int& size, int amount);
TeamRecord* linearSearchLosses(TeamRecord* recordArray, int& size, int amount);
TeamRecord* linearSearchTies(TeamRecord* recordArray, int& size, int amount);


#endif // !LINEARSEARCH_H
