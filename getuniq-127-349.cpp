//Name : K Haripriya , Employee ID : 127349

#include<iostream>
using namespace std;

//class Unique
//ary       is an array of non - unique numbers in ascending order
//count     is the number elements in the array
class Unique {
	const int* ary;
	int count;

public:

	Unique(const int* ary, int  count) : ary(ary), count(count) {}

	/*
	* @Function		GetUniqueElements(int** outary) 
	* @Description  - dynamically creates array of just required size that 
	*        		  contains unique numbers of the input array in ascending order
	*				- stores the address of the created array in outary
	* @retval		Number of unique elements
	*/
	int GetUniqueElements(int** outary) {
		
		int prev = *ary;
		int curr;
		int i;

		//get the number of unique elements
		int uniqueCount = 1;
		for (i = 1; i < count; i++) {
			curr = *(ary + i);
			if (curr != prev) {
				uniqueCount += 1;
				prev = curr;
			}
		}

		//allocate memory for the output array
		*outary = new int[uniqueCount];

		//store the unique elements in the output array
		prev = *ary;
		(*outary)[0] = prev;
		int ind = 1;
		for (i = 1; i < count; i++) {
			curr = *(ary + i);
			if (curr != prev) {
				(*outary)[ind++] = prev = curr;
			}
		}

		return uniqueCount;
	}
};


void main() {

	int input_array[] = { 0,1,1,2,4,4,6,8,9,11,11 };
	int count = sizeof(input_array) / sizeof(int);
	cout << "input array : ";
	int i;
	for (i = 0; i < count; i++) {
		cout << input_array[i] << ", ";
	}
	cout << endl;


	Unique arr(input_array, count);
	int* outarray;
	int unique_count = arr.GetUniqueElements(&outarray);
	cout << "No of unique elements in the array = " << unique_count << endl;
	cout << "output array: ";
	for (i = 0; i < unique_count; i++) {
		cout << outarray[i] << ", ";
	}
}


