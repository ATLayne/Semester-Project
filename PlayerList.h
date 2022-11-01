#ifndef PLAYERLIST_H
#define PLAYERLIST_H
#include <string>
using namespace std;

class PlayerList
{
public:
	PlayerList();
	~PlayerList();

	void appendNode(int numberInput, string nameInput);
	void insertNode();
	void deleteNode(int numToDelete);
	void displayList();

private:
	struct PlayerListNode
	{
		int playerNumber;
		string playerName;
		struct PlayerListNode* next;
	};

	PlayerListNode* head;
};

PlayerList::PlayerList()
{
	head = nullptr;
	cout << "Constructor Called." << endl;
}

PlayerList::~PlayerList()
{
}

void PlayerList::appendNode(int numberInput, string nameInput) {
	PlayerListNode* newNode;
	PlayerListNode* nodePtr;

	newNode = new PlayerListNode;
	newNode->playerNumber = numberInput;
	newNode->playerName = nameInput;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;

		while (nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
	}
}

void PlayerList::insertNode() {

}

void PlayerList::deleteNode(int numToDelete){
	PlayerListNode* nodePtr = nullptr;
	PlayerListNode* previousNode = nullptr;

	if (!head)
		return;

	if (head->playerNumber == numToDelete) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->playerNumber != numToDelete) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void PlayerList::displayList() {
	PlayerListNode* nodePtr;
	nodePtr = head;
	while (nodePtr != nullptr) {
		cout << "Number: " << nodePtr->playerNumber << " "
			 << "Name: " << nodePtr->playerName << endl;
		nodePtr = nodePtr->next;
	}
}

#endif // !PLAYERLIST_H
