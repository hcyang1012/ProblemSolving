#include <iostream>

using namespace std;


void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int *data, const int left, const int right) {

	int mid = (left + right) / 2;
	int i = left, j = right;

	int pivot = data[mid];


	while (j >= i) {
		while (data[i] < pivot) i++;
		while (data[j] > pivot) j--;
		if (j >= i) {
			swap(&data[i], &data[j]);
			i++;
			j--;
		}

	}

	if (left < j) quickSort(data, left, j);
	if (right > i) quickSort(data, i, right);

}

int main() {
	int data[] = { 4,2,3,6,1,2,5,6,3,9 };
	for (int index = 0; index < sizeof(data) / sizeof(data[0]); index++) {
		cout << data[index] << " ";
	}
	cout << endl;

	quickSort(data, 0, sizeof(data) / sizeof(data[0]) - 1);
	for (int index = 0; index < sizeof(data) / sizeof(data[0]); index++) {
		cout << data[index] << " ";
	}
}