#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Player{

private:
    int playerNumber;
    string playerName;

public:



    //Default Constructor
    Player() {
        playerNumber = 0;
        playerName = "First Last";
    }

    //Custom Constructor
    Player(const string name, const int playerNumber){
        setPlayerInfo(name, playerNumber);
    }   

    //Destructor
    ~Player(){
        //cout << "Destructor Called" << endl;
    }

    //Copy Constructor
    Player(const Player& originalPlayer){
        playerName = originalPlayer.playerName;
        playerNumber = originalPlayer.playerNumber;
    }

    //Assignment Operator Overload
    Player& operator=(const Player& rightSide){
        playerName = rightSide.playerName;
        playerNumber = rightSide.playerNumber;
        return *this;
    }

    //Setting player info from file. Loop is defined in the main.cpp file
    void setPlayerInfo(const string name, const int number){
        this->playerName = name;
        this->playerNumber = number;
    }

    int getPlayerNumber() const {
        return playerNumber;
    }

    string getPlayerName() const {
        return playerName;
    }

    void display(){
        cout << left;
        cout << "Name: " << setw(25) << this->playerName << "Number: " << this->playerNumber << endl;
        //cout << "Number: " << this->playerNumber << endl;
    }
};

#endif
