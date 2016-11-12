#include <iostream>
using namespace std;

int extendLargeRegion(int *data, int pivot, const int lowVacant, const int high) {
	int highVacant, currentIndex;
	highVacant = lowVacant;
	currentIndex = high;
	while (currentIndex > lowVacant) {
		if (data[currentIndex] < pivot) {
			data[lowVacant] = data[currentIndex];
			highVacant = currentIndex;
			break;
		}
		currentIndex--;
	}
	return highVacant;
}

int extendSmallRegion(int *data, const int pivot, const int low, const int highVacant) {
	int lowVacant, currentIndex;
	lowVacant = highVacant;

	currentIndex = low;

	while (currentIndex < highVacant) {
		if (data[currentIndex] >= pivot) {
			data[highVacant] = data[currentIndex];
			lowVacant = currentIndex;
			break;
		}
		currentIndex++;
	}
	return lowVacant;
}

int partition(int *data, const int pivot, const int first, const int last) {
	int low, high;
	low = first;
	high = last;

	while (low < high) {
		int highVacantIndex = extendLargeRegion(data, pivot, low, high);
		int lowVacantIndex = extendSmallRegion(data, pivot, low + 1, highVacantIndex);

		low = lowVacantIndex;
		high = highVacantIndex - 1;
	}

	return low;
}

void quickSort(int *data, const int first, const int last) {
	if (first < last) {
		int pivot = data[first];
		int splitPoint = partition(data, pivot, first, last);
		data[splitPoint] = pivot;
		quickSort(data, first, splitPoint - 1);
		quickSort(data, splitPoint + 1, last);
	}
}

int main() {
	int data[] = { 1,4,5,2,3,7,5,10,22,11,13 };
	const int size = sizeof(data) / sizeof(int);

	for (int index = 0; index < size; index++) {
		cout << data[index] << " ";
	}
	cout << endl;

	quickSort(data, 0, size - 1);

	for (int index = 0; index < size; index++) {
		cout << data[index] << " ";
	}
	cout << endl;


	return 0;
}