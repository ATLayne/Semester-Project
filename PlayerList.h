#ifndef PLAYERLIST_H
#define PLAYERLIST_H
#include <string>
#include <iomanip>
using namespace std;

class PlayerList
{
public:
	PlayerList();
	~PlayerList();

	void appendNode(int numInput, string nameInput, int ageInput, string posInput);
	void insertNode(int numInput, string nameInput, int ageInput, string posInput);
	void deleteNode(int numToDelete);
	void displayList();

private:
	struct PlayerListNode
	{
		int playerNumber;
		string playerName;
		int playerAge;
		string playerPOS;
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

void PlayerList::appendNode(int numInput, string nameInput, int ageInput, string posInput) {
	PlayerListNode* newNode;
	PlayerListNode* nodePtr;

	newNode = new PlayerListNode;
	newNode->playerNumber = numInput;
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

void PlayerList::insertNode(int numInput, string nameInput, int ageInput, string posInput) {
	PlayerListNode* newNode;
	PlayerListNode* nodePtr;
	PlayerListNode* previousNode = nullptr;

	newNode = new PlayerListNode;
	newNode->playerName = nameInput;
	newNode->playerNumber = numInput;
	newNode->playerAge = ageInput;
	newNode->playerPOS = posInput;


	if (!head) {
		head = newNode;
		newNode->next = nullptr;
	}
	else {
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->playerNumber < numInput) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
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

//void PlayerList::sortList() {
//	PlayerListNode* nodePtr;
//	PlayerListNode* tempNode;
//	//int tempNum;
//	//string tempName;
//	nodePtr = head;
//	tempNode = new PlayerListNode;
//
//	bool sorted = false;
//
//	while (nodePtr != nullptr && sorted == false) {
//		if (nodePtr->playerNumber < nodePtr->next->playerNumber) {
//			tempNode = nodePtr->next;
//			nodePtr->next = nodePtr;
//			nodePtr = tempNode;
//			sorted = false;
//		}
//		else {
//			sorted = true;
//		}
//		nodePtr = nodePtr->next;
//	}
//}

void PlayerList::displayList() {
	PlayerListNode* nodePtr;
	nodePtr = head;

	cout << endl << left;
	cout << setfill(' ') << setw(0) << "Number"
		<< setfill(' ') << setw(8) << " " << "Name"
		<< setfill(' ') << setw(15) << " " << "Age"
		<< setfill(' ') << setw(5) << " " << "Position" << endl;
	cout << endl;


	while (nodePtr != nullptr) {
		cout << left;
		cout << setw(7) << nodePtr->playerNumber << " "
			 << setw(25) << nodePtr->playerName << " "
			 << setw(10) << nodePtr->playerAge << " "
			 << setw(10) << nodePtr->playerPOS << endl;
		nodePtr = nodePtr->next;
	}
}

#endif // !PLAYERLIST_H
