#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	int value;
	Node *left;
	Node *right;
public:
	Node(const int value) : value(value) {
		left = NULL;
		right = NULL;
	}

	void setLeft(Node *const node) {
		left = node;
	}

	void setRight(Node *const node) {
		right = node;
	}

	Node *getLeft() const {
		return left;
	}

	Node *getRight() const {
		return right;
	}

	int getValue() const {
		return value;
	}
};

Node *getCommonParent(Node *root, const Node *A, const Node *B) {
	if (root != NULL) {
		bool AisLarger = false;
		bool BisLarger = false;

		AisLarger = root->getValue() < A->getValue();
		BisLarger = root->getValue() < B->getValue();

		if (AisLarger != BisLarger) {
			return root;
		}
		else {
			if (AisLarger) {
				return getCommonParent(root->getRight(), A, B);
			}else{
				return getCommonParent(root->getLeft(), A, B);
			}
		}

	}
}


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
	N4->setRight(N12);

	N12->setLeft(N10);
	N12->setRight(N14);

	Node *commonParent = NULL;
	commonParent = getCommonParent(root, N14, N22);

	if (commonParent != NULL) {
		cout << commonParent->getValue() << endl;
	}

	return 0;
	
}