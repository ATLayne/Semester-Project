//Austin Layne
//Nathaniel Moreno


#ifndef PLAYER_H
#define PLAYER_H
#include "person.h"
using namespace std;

//Player class is used to contain objects of players.
//It is now derived from the person class and only implements 
//members for a players number and a players position.
class Player : public Person {

private:
    int playerNumber;
    string playerPOS;

public:
    //Default Constructor
    Player();

    //Custom Constructor
    Player(const string name, const int playerNumber, const int playerAge, const string playerPOS);

    //Destructor
    ~Player();

    //Copy Constructor
    Player(const Player& originalPlayer);

    //Assignment Operator Overload
    Player& operator=(const Player& rightSide);

    //Setting player info from file. Loop is defined in the main.cpp file
    void setPlayerInfo(const string name, const int number, const int age, const string pos);

    int getPlayerNumber() const;

    string getPlayerName() const;

    string getPlayerPOS() const;

    void display();
};

//Default Constructor
Player::Player() {
    playerNumber = 0;
    personName = "First Last";
}

//Custom Constructor
Player::Player(const string name, const int playerNumber, const int playerAge, const string playerPOS) {
    setPlayerInfo(name, playerNumber, playerAge, playerPOS);
}

//Destructor
Player::~Player() {
    //cout << "Destructor Called" << endl;
}

//Copy Constructor
Player::Player(const Player& originalPlayer) {
    personName = originalPlayer.personName;
    playerNumber = originalPlayer.playerNumber;
    playerPOS = originalPlayer.playerPOS;
}

//Assignment Operator Overload
Player& Player::operator=(const Player& rightSide) {
    personName = rightSide.personName;
    playerNumber = rightSide.playerNumber;
    playerPOS = rightSide.playerPOS;
    return *this;
}

//Setting player info from file. Loop is defined in the main.cpp file
void Player::setPlayerInfo(const string name, const int number, const int age, const string pos) {
    (*this).personName = name;
    (*this).playerNumber = number;
    (*this).personAge = age;
    (*this).playerPOS = pos;
}

int Player::getPlayerNumber() const {
    return playerNumber;
}

string Player::getPlayerName() const {
    return personName;
}

string Player::getPlayerPOS() const {
    return playerPOS;
}

//display function overrides the Person.display() function of the base class.
void Player::display() {
    cout << left;
    cout << setw(23) << (*this).personName
        << setw(17) << this->playerNumber
        << setw(11) << this->personAge
        << setw(5) << this->playerPOS << endl;
}




#endif
