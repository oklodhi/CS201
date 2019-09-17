// Omer Khan 
// mokddp@mail.umkc.edu
// April 4
// CS201L Lab 10

/* Dear Mr. Landon, this lab was a doozy. I do have a general idea of a linked list. A linked list is a set of data saved as nodes in the list. Each node is "linked" to its predecessors and successor nodes using pointers and whatnot. So we point to the "head" or starting node, which then points to the next node/item in the list and so on...
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class StudentInfo {
private:
	string name;
	StudentInfo* nextStudentPtr = nullptr;
public:
	StudentInfo(string value, StudentInfo* nextItem) {
		this->name = value; 
		this->nextStudentPtr = nextItem;
	}
	string getName() {
		return name;
	}
	StudentInfo* getNextStudent() {
		return this->nextStudentPtr;
	}
	void setNextStudent(StudentInfo* item) {
		this->nextStudentPtr = item;
		
		/*StudentInfo* tmpNext = nullptr;

		tmpNext = this->nextStudentPtr; 
		this->nextStudentPtr = item; 
		item->nextStudentPtr = tmpNext;*/
	}
};

class LinkedList {
private: 
	StudentInfo *headPtr = nullptr;
	StudentInfo *currentPtr = nullptr;
	StudentInfo *tempPtr = nullptr;
public: 
	/*StudentInfo *getHeadPtr() {
		return headPtr;
	}*/
	/*void setheadPtr(StudentInfo *ptr) {
		headPtr = ptr;
	}*/
	void node_update(string item, string cmd) {

		if (cmd == "add") {
			while ((currentPtr != nullptr) && (item > currentPtr->getNextStudent()->getName())) {
				tempPtr = currentPtr;
				currentPtr = currentPtr->getNextStudent();
			}
			StudentInfo *nextPtr = nullptr;

			if ((currentPtr != nullptr) && (currentPtr->getNextStudent() != nullptr)) {
				nextPtr = currentPtr->getNextStudent();
			}
			currentPtr = new StudentInfo(item, nextPtr);
			
			if (tempPtr != nullptr) {
				tempPtr->setNextStudent(currentPtr);
			}

		}
		else if (cmd == "del") {
			while (item != currentPtr->getName()) {
				tempPtr = currentPtr;
				currentPtr = currentPtr->getNextStudent();
			}
			tempPtr->setNextStudent(currentPtr->getNextStudent());
			delete currentPtr; 
			currentPtr = nullptr;
		}
	}
	void node_print() {
		StudentInfo *currentPtr = headPtr; 
		while (currentPtr != nullptr) {
			cout << " -> " << currentPtr->getName();
			currentPtr = currentPtr->getNextStudent();
		}
	}
};

int main() {

	// Declare any extra variables needed
	const string INPUT1 = "input1.txt"; 
	const string INPUT2 = "input2.txt";
	const string INPUT3 = "input3.txt";
	const string INPUT4 = "input4.txt";
	const string INPUT5 = "input5.txt";
	const string INPUT6 = "input6.txt";
	const string INPUT7 = "input7.txt";

	LinkedList list;

	ifstream fin(INPUT1);
	
	if (!fin.is_open())
	{
		cout << "Could not open the input file input1.txt" << endl;
		return -1;
	}
	
	while (!fin.eof())
	{
		string item, command;
		fin >> item >> command;

		// Logic of handling the input.
		list.node_update(item, command);
	}
	fin.close();

	// Output the final linked list.

	// Free up all memory.

}