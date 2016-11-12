#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/* 
Vertexes 
0	1	2	3	4	5	6	7	8
SFO	LAX	DFW	ORD	BOS	PVD	JFK	BWI	MIA
*/

#define NUM_OF_VERTEXES 9
#define INF 9999

#define VISITED 1
#define UNVISITED 0

class Dijkstra {
public:
	Dijkstra(){
		reset();
	}

	void reset() {
		for (int index = 0; index < NUM_OF_VERTEXES; index++) {
			visitList[index] = UNVISITED;
		}
		numOfVisitedVertex = 0;
	}

	void doDijkstra(const int start, int *distanceList, const int graph[NUM_OF_VERTEXES][NUM_OF_VERTEXES]) {
		reset();
		for (int index = 0; index < NUM_OF_VERTEXES; index++) {
			distanceList[index] = INF;
		}
		distanceList[start] = 0;

		while (!isEmpty()) {
			int currentVisitVertex = removeMin(distanceList);
			if (currentVisitVertex == -1) {
				throw new exception();
			}
			for (int index = 0; index < NUM_OF_VERTEXES; index++) {
				if (graph[currentVisitVertex][index] != INF && visitList[index] == UNVISITED) {
					if (distanceList[currentVisitVertex] + graph[currentVisitVertex][index] < distanceList[index]) {
						distanceList[index] = distanceList[currentVisitVertex] + graph[currentVisitVertex][index];
					}
				}
			}
		}

	}
private:
	int visitList[NUM_OF_VERTEXES];

	int numOfVisitedVertex;
	bool isEmpty() const { return numOfVisitedVertex == NUM_OF_VERTEXES; }
	int removeMin(const int *distanceList) {
		int minValue = INF;
		int minIndex = -1;
		for (int index = 0; index < NUM_OF_VERTEXES; index++) {
			if (visitList[index] == UNVISITED && distanceList[index] <= minValue) {
				minIndex = index;
				minValue = distanceList[minIndex];
			}
		}
		if (minIndex != -1) {
			visitList[minIndex] = VISITED;
			numOfVisitedVertex++;
		}
		return minIndex;
	}
};
int main() {
	string vertexes[NUM_OF_VERTEXES] = { "SFO", "LAX", "DFW", "ORD", "BOS", "PVD", "JFK", "BWI", "MIA" };
	int graph[NUM_OF_VERTEXES][NUM_OF_VERTEXES] = {
		{ 0, 337, 1464, 1846, 2704, INF, INF, INF, INF },
		{ 337, 0, 1235, INF, INF, INF, INF, INF, 2342 },
		{ 1464, 1235, 0, 802, INF, INF, 1391, INF, 1121 },
		{ 1846, INF, 802, 0, 867, 849, 740, 621, INF },
		{ 2704, INF, INF, 867, 0, INF, 187, INF, 1258 },
		{ INF, INF, INF, 849, INF, 0, 144, INF, INF },
		{ INF, INF, 1391, 740, 187, 144, 0, 184, 1090 },
		{ INF, INF, INF, 621, INF, INF, 184, 0, 946 },
		{ INF, 2342, 1121, INF, 1258, INF, 1090, 946, 0 }
	};

	

	try {
		int distances[NUM_OF_VERTEXES];
		Dijkstra dijkstra;
		dijkstra.doDijkstra(7, distances, graph);
		for (int index = 0; index < NUM_OF_VERTEXES; index++) {
			cout << vertexes[index] << " : " << distances[index] << endl;
		}
	}
	catch (exception e) {
		cout << "Error" << endl;
	}

	return 0;
}