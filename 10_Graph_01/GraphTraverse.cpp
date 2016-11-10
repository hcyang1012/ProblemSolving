#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Vertex {
public:
	Vertex(const string& name) : name(name) {

	}

	string getName() const { return name; }
private:
	const string name;
};

class Graph {
public:
	void clearGraph() {
		vertexes.clear();
		edges.clear();
	}

	void addVertex(const Vertex *newVertex) {
		vertexes.insert(newVertex);
		if (edges.find(newVertex) == edges.end()) {
			set<const Vertex*> *newEdges = new set<const Vertex*>;
			edges[newVertex] = newEdges;
		}
	}

	void addEdge(const Vertex *start, const Vertex *adjacentVertex) {
		if(edges.find(start) != edges.end()){
			edges[start]->insert(adjacentVertex);
		}
	}

	void DFS(const Vertex *start, set<const Vertex*> *visitedEdge = NULL) const {
		if (visitedEdge == NULL) {
			visitedEdge = new set<const Vertex*>;
		}
		visitedEdge->insert(start);
		cout << start->getName() << " ";
		set<const Vertex*>  *adjacentList = edges.find(start)->second;
		for (set<const Vertex*>::const_iterator itor = adjacentList->cbegin(); itor != adjacentList->cend(); ++itor) {
			set<const Vertex*>::const_iterator nextVisitVertexItor = visitedEdge->find(*itor);
			if (nextVisitVertexItor == visitedEdge->cend()) {
				DFS(*itor, visitedEdge);
			}
		}
	}

	void BFS(const Vertex *start, set<const Vertex*> *visitedEdge = NULL) const {
		if (visitedEdge == NULL) {
			visitedEdge = new set<const Vertex*>;
		}
		visitedEdge->insert(start);
		cout << start->getName() << " ";
		
		set<const Vertex*> *currentLevelList = new set<const Vertex*>;
		currentLevelList->insert(start);
		while (!currentLevelList->empty()) {
			set<const Vertex*> *nextLevelList = new set<const Vertex*>;
			for (set<const Vertex*>::const_iterator itor = currentLevelList->cbegin(); itor != currentLevelList->cend(); ++itor) {
				set<const Vertex*> *adjacentVertexes = edges.find(*itor)->second;
				for (set<const Vertex*>::const_iterator adjacentItor = adjacentVertexes->cbegin(); adjacentItor != adjacentVertexes->cend(); ++adjacentItor) {
					if (visitedEdge->find(*adjacentItor) == visitedEdge->cend()) {
						visitedEdge->insert(*adjacentItor);
						cout << (*adjacentItor)->getName() << " ";
						nextLevelList->insert(*adjacentItor);
					}
				}
			}
			set<const Vertex*> *temp = currentLevelList;
			currentLevelList = nextLevelList;
			free(temp);
		}
	}

	Graph() {
		clearGraph();
	}
private:
	set<const Vertex*> vertexes;
	map<const Vertex*, set<const Vertex*>*> edges;
};



int main() {
	Vertex V_A("A");
	Vertex V_B("B");
	Vertex V_C("C");
	Vertex V_D("D");
	Vertex V_E("E");
	Vertex V_F("F");
	Vertex V_G("G");
	Vertex V_H("H");
	Vertex V_I("I");
	Vertex V_J("J");
	Vertex V_K("K");
	Vertex V_L("L");
	Vertex V_M("M");
	Vertex V_N("N");
	Vertex V_O("O");
	Vertex V_P("P");


	Graph graph;

	graph.addVertex(&V_A);
	graph.addVertex(&V_B);
	graph.addVertex(&V_C);
	graph.addVertex(&V_D);
	graph.addVertex(&V_E);
	graph.addVertex(&V_F);
	graph.addVertex(&V_G);
	graph.addVertex(&V_H);
	graph.addVertex(&V_I);
	graph.addVertex(&V_J);
	graph.addVertex(&V_K);
	graph.addVertex(&V_L);
	graph.addVertex(&V_M);
	graph.addVertex(&V_N);
	graph.addVertex(&V_O);
	graph.addVertex(&V_P);

	graph.addEdge(&V_A, &V_B);
	graph.addEdge(&V_A, &V_E);
	graph.addEdge(&V_A, &V_F);
	
	graph.addEdge(&V_B, &V_A);
	graph.addEdge(&V_B, &V_C);
	graph.addEdge(&V_B, &V_F);

	graph.addEdge(&V_C, &V_B);
	graph.addEdge(&V_C, &V_D);
	graph.addEdge(&V_C, &V_G);

	graph.addEdge(&V_D, &V_C);
	graph.addEdge(&V_D, &V_G);
	graph.addEdge(&V_D, &V_H);

	graph.addEdge(&V_E, &V_A);
	graph.addEdge(&V_E, &V_F);
	graph.addEdge(&V_E, &V_I);

	graph.addEdge(&V_F, &V_A);
	graph.addEdge(&V_F, &V_B);
	graph.addEdge(&V_F, &V_E);

	graph.addEdge(&V_G, &V_C);
	graph.addEdge(&V_G, &V_D);
	graph.addEdge(&V_G, &V_J);
	graph.addEdge(&V_G, &V_K);
	graph.addEdge(&V_G, &V_L);

	graph.addEdge(&V_H, &V_D);
	graph.addEdge(&V_H, &V_L);

	graph.addEdge(&V_I, &V_E);
	graph.addEdge(&V_I, &V_F);
	graph.addEdge(&V_I, &V_J);
	graph.addEdge(&V_I, &V_M);
	graph.addEdge(&V_I, &V_N);

	graph.addEdge(&V_J, &V_G);
	graph.addEdge(&V_J, &V_I);
	graph.addEdge(&V_J, &V_K);

	graph.addEdge(&V_K, &V_G);
	graph.addEdge(&V_K, &V_J);
	graph.addEdge(&V_K, &V_N);
	graph.addEdge(&V_K, &V_O);

	graph.addEdge(&V_L, &V_G);
	graph.addEdge(&V_L, &V_H);
	graph.addEdge(&V_L, &V_P);

	graph.addEdge(&V_M, &V_I);
	graph.addEdge(&V_M, &V_N);

	graph.addEdge(&V_N, &V_I);
	graph.addEdge(&V_N, &V_K);
	graph.addEdge(&V_N, &V_M);

	graph.addEdge(&V_O, &V_K);
	graph.addEdge(&V_O, &V_P);

	graph.addEdge(&V_P, &V_L);
	graph.addEdge(&V_P, &V_O);




	cout << "DFS : ";
	graph.DFS(&V_A);
	cout << endl;

	cout << "BFS : ";
	graph.BFS(&V_A);
	cout << endl;

	return 0;
}