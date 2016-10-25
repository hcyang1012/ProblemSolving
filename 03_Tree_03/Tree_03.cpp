#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Node {
private:
	int value;
	Node *left;
	Node *right;
public:
	Node(const int value) : value(value) {
		left = right = NULL;
	}

	void setLeft(Node *node) {
		this->left = node;
	}

	void setRight(Node *node) {
		this->right = node;
	}

	Node* getLeft() const {
		return this->left;
	}

	Node* getRight() const {
		return this->right;
	}

	int getValue() const {
		return this->value;
	}

	const bool operator<(const Node& B) const {
		return getValue() < B.getValue();
	}

};
int main(void) {
	Node *root = new Node(20);
	Node *N8 = new Node(8);
	Node *N22 = new Node(22);
	Node *N4 = new Node(4);
	Node *N12 = new Node(12);
	Node *N10 = new Node(10);
	Node *N14 = new Node(14);

	root->setLeft(N8);
	root->setRight(N22);

	N8->setLeft(N4);
	N8->setRight(N12);
	
	N12->setLeft(N10);
	N12->setRight(N14);

	vector<Node> nodeVector;
	nodeVector.push_back(*root);
	nodeVector.push_back(*N8);
	nodeVector.push_back(*N22);
	nodeVector.push_back(*N4);
	nodeVector.push_back(*N12);
	nodeVector.push_back(*N10);
	nodeVector.push_back(*N14);

	sort(nodeVector.begin(), nodeVector.end());

	Node *newRoot = NULL;
	newRoot = &nodeVector.at(0);
	for (unsigned  index = 0; index < nodeVector.size(); index++) {
		Node *currentNode = &nodeVector.at(index);
		unsigned int leftIndex = index * 2 + 1;
		unsigned int rightIndex = leftIndex + 1;

		if (rightIndex < nodeVector.size()) {
			currentNode->setRight(&nodeVector.at(rightIndex));
		}
		else {
			currentNode->setRight(NULL);
		}
		if(leftIndex < nodeVector.size()) {
			currentNode->setLeft(&nodeVector.at(leftIndex));
		}
		else {
			currentNode->setLeft(NULL);
		}
	}
	return 0;
}