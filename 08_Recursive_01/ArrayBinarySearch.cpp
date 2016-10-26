#include <iostream>
using namespace std;


const int* arrayBinarySearch(const int value, const int *inputArray, const int arraySize) {
	int mid = arraySize / 2;
	if (inputArray[mid] == value) {
		return &inputArray[mid];
	}
	if (arraySize == 1) {
		return NULL;
	}

	if (inputArray[mid] < value) {
		return arrayBinarySearch(value, &inputArray[mid], arraySize - mid);
	}

	if (inputArray[mid] > value) {
		return arrayBinarySearch(value, &inputArray[0], mid);
	}	
}

int main(void) {
	int inputArray[] = { 1,2,3,4,5,6,7,8,9,10 };
	const int *searchResult = arrayBinarySearch(2, inputArray, sizeof(inputArray) / sizeof(inputArray[0]));
	if (searchResult != NULL) {
		cout << *searchResult << endl;
	}
	else {
		cout << "Not found" << endl;
	}
	
	return		0;
}