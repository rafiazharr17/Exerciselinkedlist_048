#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** azhar, Node** rafi);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { 
	int nim; //membuat tipe data integer dengan nama variabel nim
	string nm; //membuat tipe data string dengan nama variabel nm
	cout << "\nEnter the roll number of the student : ";
	cin >> nim; //dimasukin ke nim
	cout << "\nEnter the name of the student : ";
	cin.ignore();
	getline(cin, nm);
	Node* newNode = new Node();	//membuat pointer Node ke newNode
	newNode->rollNumber = nim;	
	newNode->name = nm;

	if (LAST == NULL || nim <= LAST->rollNumber) { //apabila last sama dengan null atau nim kurang dari last->rollNumber
		if (LAST != NULL && nim == LAST->rollNumber) {	//apabila last tidak sama dengan null dan nim last->rollNumber
			cout << "Buat linked list terlebih dahulu" << endl; //keluar tampilan tersebut
			return;
		}

		LAST = newNode; //membuat last menjadi newNode
		newNode->next = LAST; //newNode kemudian menjadi last
		return;
	}

	Node* rafi = LAST;
	Node* azhar = NULL;

	
	
}

bool CircularLinkedList::search(int rollno, Node** azhar, Node** rafi) {
	*azhar = LAST->next;
	*rafi = LAST->next;
	while (*rafi != LAST) {
		if (rollno == (*rafi)->rollNumber) {
			return true;
		}
		*azhar = *rafi;
		*rafi = (*rafi)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() { 
	if (listEmpty()) {	//jika kosong
		cout << "List is empty" << endl; //maka keluar tampilan tersebut
		return false;	//ulangin jika kosong
	}

	if (LAST->next == LAST) {	//apabila last kemudian berjalan dan tetap sama dengan last
		delete LAST;	//hapus last
		LAST = NULL;	//last menjadi null
	}
	else {	//jika tidak
		Node* rafi = LAST->next;	//rafi menjadi last next
		LAST->next = rafi->next;	//last next menjadi rafi next
		delete rafi;				//hapus rafi
	}
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* rafiNode = LAST->next;
		while (rafiNode != LAST) {
			cout << rafiNode->rollNumber << " " << rafiNode->name << endl;
			rafiNode = rafiNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}