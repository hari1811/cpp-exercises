//Name : K Haripriya , Employee ID : 127349

#include<iostream>
using namespace std;

//number of memory locations in a single node
const int NUM = 4;

//Class node
class node {
	int data[NUM];

public:
	node* prevHead;

	node(int i, node* p): prevHead(p){
		data[0] = i;
		cout << "Node multi parameter Constructor called with data : " << i << "\n" << endl;
	}

	~node() {
		cout << "Node Destructor called\n" << endl;
	}

	//function to store data into the array of the node 
	void push(int i, int index) {
		data[index] = i;
	}

	//function to get data from the node
	int get(int index) {
		return data[index];
	}
};

//class dynStack (dynamic Stack)
class dynStack {
	node* head;
	int index;

public:
	dynStack() : index(4), head(NULL) {
		cout << "dynStack Constructor called\n" << endl;
	}

	~dynStack() {
		cout << "dynStack Destructor called\n" << endl;
	}

	dynStack& operator ++(); // to push data into stack
	int operator --(); // to pop data from stack
	dynStack& operator --(int);//to pop all the data from the stack
	friend ostream& operator << (ostream& , dynStack& ); //to display the contents of the stack
};


ostream& operator << (ostream& cout, dynStack& stack){
	int ind = stack.index;
	if (stack.head) {
		cout << "Stack contents: ";

		for (node* trav = stack.head; trav; trav = trav->prevHead, ind = NUM) {
			while (ind > 0) {
				cout << trav->get(ind - 1) << " ";
				ind -= 1;
			}
		}
		cout << "\n" <<  endl;
	}
	else
		cout << " No node to display \n" << endl;
	return cout;
}

dynStack& dynStack::operator++() {  
	int val = 0;
	cout << "Enter value to be pushed: ";
	cin >> val;
	cout << "\n";
	if (index >= NUM) {
		head = new node(val, head);
		index = 1;
	}
	else {
		head->push(val, index++);
	}
	return *this;
}

//return : returns popped value
int dynStack::operator--() {
	int val = NULL;
	if (head == NULL) {
		cout << "Stack is empty, nothing to pop!\n" << endl;
	}
	else if (index == 1) {
		val = head->get(index - 1);
		index = NUM;
		cout << "popped value " << val << endl;
		node* temp  = head;
		head = head->prevHead;
		delete temp;
	}
	else {
		val = head->get(index - 1);
		index -= 1; 
		cout << "popped value " << val << endl;
	}
	return val;
}

dynStack& dynStack::operator--(int) {
	if (head) {
		node* temp;
		while (head) {
			temp = head;
			head = head->prevHead;
			delete temp;
		}
		index = NUM;
		cout << "Emptied stack\n" << endl;
	}
	else
		cout << "Stack is Empty\n";
	return *this;
}


void main() {
	dynStack stack = dynStack();

	int action = 0;

	while (1) {
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. PopAll\n";
		cout << "4. Display\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> action;
		cout << "\n";
		switch (action) {
		case 1: ++stack; break;
		case 2: --stack; break;
		case 3: stack--; break;
		case 4: cout << stack; break;
		case 5:
		default:
			cout << " ... Exiting from app ...\n";
			stack--;
			stack.~dynStack();
			exit(0);
		}
	}
}