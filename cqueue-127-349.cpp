//Name : K Haripriya , Employee ID : 127349

#include <iostream>
using namespace std;

//Class CQueue: Circular queue
class CQueue{
	int* pvalue;
	int start;
	int FilledLen;
	int Size;

public:

	CQueue() : FilledLen(0), Size(0), pvalue(NULL), start(0){}

	void printQueue() {
		if (FilledLen == 0) {
			cout << "Queue is Empty!";
			return;
		}
		cout << "Queue elements: ";
		int i;
		for (i = 0; i < FilledLen; i++) {
			cout << *(pvalue + (start + i)%Size) << " ";
		}
		cout << endl;
	}


	/*
	*	@Function		CQueueInit(int qsize)
	*	@description	Allocates dynamic memory for array of size “qsize”
	*	@retval			0 if successful; -1 otherwise
	*/
	int CQueueInit(int qsize){

		int ret;

		if (qsize <= 0) {
			cout << "Queue size must be greater than zero." << endl;
			ret = -1;
		}
		else if (!(pvalue = new(nothrow) int[qsize])) {
			cout << "Error: out of memory." << endl;
			ret = -1;
		}
		else {
			Size = qsize;
			cout << "Initialised Queue with size: " << qsize << endl;
			ret = 0;
		}
		
		return ret;
	}

	/*
	*	@Function		CQInsert(int val)
	*	@description	inserts val into circular queue if queue is not full
	*	@retval			0 if successful; -1 otherwise.
	*/
	int CQInsert(int val){
		if (Size == 0) {
			cout << "Queue not initialised with size!" << endl;
			return -1;
		}
		else if (FilledLen >= Size){
			cout << "Cannot Insert: Queue is full!" << endl;
			return -1;
		}
		else {
			*(pvalue + (start + FilledLen)%Size) = val;
			FilledLen += 1;
			cout << "Inserted element: " << val << ".......";
			printQueue();
			return 0;
		}
		
	}

	/*
	*	@Function		CQRemove(int* pval) 
	*	@description	removes data from circular queue if queue is not empty
	*					the data removed is stored in location pointed by pval
	*	@retval			0 if successful; -1 otherwise.
	*/
	int CQRemove(int* pval) {

		if (Size == 0) {
			cout << "Queue not initialised with size!" << endl;
			return -1;
		}
		if (FilledLen <= 0) {
			cout << "Nothing to remove: Queue is empty!" << endl;
			return -1;
		}
		else {
			*pval = pvalue[start];
			start = (start + 1) % Size;
			FilledLen -= 1;
			cout << "Removed element: " << *pval << ".......";
			printQueue();
			return 0;
		}
	}

	/*
	*	@Function		CQueueCleanup() 
	*	@description	Frees dynamically allocated memory
	*	@retval			0 if successful; -1 otherwise.
	*/
	int CQueueCleanup() {
		if (Size > 0) {
			delete [] pvalue;
			pvalue = NULL;
			Size = 0;
			cout << "Cleaned up Queue." << endl;
			return 0;
		}

		else {
			cout << "Queue not initialised with size!"  << endl;
			return -1;
		}

	}

};

void main() {

	//Creating queue object
	CQueue queue1;

	int value;

	//Test case: Insert, remove , Cleanup without initialisation
	queue1.CQInsert(8);
	queue1.CQRemove(&value);
	queue1.CQueueCleanup();
	cout << "------------------------------\n" << endl;

	//Test case: Initialising queue with invalid size
	queue1.CQueueInit(-5);
	queue1.CQueueInit(0);
	cout << "------------------------------\n" << endl;

	//Initialising queue
	queue1.CQueueInit(5);

	//Test case: Removing when queue is empty
	queue1.CQRemove(&value);
	cout << "Main: popped value = " << value << endl << endl;
	cout << "------------------------------\n" << endl;

	//Test case: valid queue operations
	queue1.CQInsert(0);
	queue1.CQInsert(8);
	queue1.CQRemove(&value);
	cout << "Main: popped value = " << value << endl << endl;
	queue1.CQInsert(3);
	queue1.CQInsert(28);
	queue1.CQInsert(6);
	queue1.CQInsert(67);
	queue1.CQInsert(9);
	queue1.CQRemove(&value);
	cout << "Main: popped value = " << value << endl << endl;
	queue1.CQueueCleanup();
	cout << "------------------------------\n" << endl;

	//Test case: Cleanup after queue is deleted
	queue1.CQueueCleanup();
	cout << "------------------------------\n" << endl;

}





