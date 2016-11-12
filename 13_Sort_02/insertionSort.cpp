#include <iostream>

using namespace std;

int shiftVector(int *elements, int xIndex, const int target) {
	int vacant, xLoc;
	xLoc = 0;

	vacant = xIndex;
	while (vacant > 0) {
		if (elements[vacant - 1] <= target) {
			xLoc = vacant;
			break;
		}
		elements[vacant] = elements[vacant - 1];
		vacant--;
	}
	return xLoc;
}


void insertionSort(int *elements, const int size) {

	for (int xIndex = 1; xIndex < size; xIndex++) {
		int current = elements[xIndex];
		int xLoc = shiftVector(elements, xIndex, current);
		elements[xLoc] = current;
	}
}

int main() {
	int target[] = { 1,10,3,5,2,3,7,4,9,8,11 };
	for (int index = 0; index < sizeof(target) / sizeof(int); index++) {
		cout << target[index] << " ";
	}
	cout << endl;

	insertionSort(target, sizeof(target) / sizeof(int));

	for (int index = 0; index < sizeof(target) / sizeof(int); index++) {
		cout << target[index] << " ";
	}
	cout << endl;
	return 0;
}