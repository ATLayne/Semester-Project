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
    string playerPOS;

public:



    //Default Constructor
    Player() {
        playerNumber = 0;
        playerName = "First Last";
    }

    //Custom Constructor
    Player(const string name, const int playerNumber, const string playerPOS){
        setPlayerInfo(name, playerNumber, playerPOS);
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
    void setPlayerInfo(const string name, const int number, const string pos){
        (*this).playerName = name;
        (*this).playerNumber = number;
        (*this).playerPOS = pos;
    }

    int getPlayerNumber() const {
        return playerNumber;
    }

    string getPlayerName() const {
        return playerName;
    }

    string getPlayerPOS() const {
        return playerPOS;
    }

    void display(){
        cout << left;
        cout << setw(23) << (*this).playerName << setw(11) << this->playerNumber << setw(5) << this->playerPOS << endl;
        //cout << "Number: " << this->playerNumber << endl;
    }
};

#endif
