#include <iostream>

using namespace std;

#define INF 9999
#define UNKNOWN -1
#define NUM_OF_DIMENSIONS 5



int matrixOrder(const int N, const int *dimensions, int (*costs)[NUM_OF_DIMENSIONS], int (*lasts)[NUM_OF_DIMENSIONS]) {
	int bestCost, bestLast;
	for (int low = N - 1; low >= 0; low--) {
		for (int high = low + 1; high <= N; high++) {
			if (high - low == 1) {
				bestCost = 0;
				bestLast = UNKNOWN;
			}else{
				bestCost = INF;
			}

			for (int k = low + 1; k < high; k++) {
				int a = costs[low][k];
				int b = costs[k][high];
				int c = dimensions[low] * dimensions[k] * dimensions[high];

				if (a + b + c < bestCost) {
					bestCost = a + b + c;
					bestLast = k;
				}
			}
			costs[low][high] = bestCost;
			lasts[low][high] = bestLast;
		}
	}

	return costs[0][N];
}

int main() {


	int costs[NUM_OF_DIMENSIONS][NUM_OF_DIMENSIONS];
	int lasts[NUM_OF_DIMENSIONS][NUM_OF_DIMENSIONS];
	int matrixDimenstion[NUM_OF_DIMENSIONS] = { 30,1,40,10,25 };
	
	cout << matrixOrder(NUM_OF_DIMENSIONS - 1, matrixDimenstion, costs, lasts) << endl;
	return 0;
}