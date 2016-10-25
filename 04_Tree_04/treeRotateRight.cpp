#include <iostream>

using namespace std;

class Node{
	private:
		int value;
		Node *left;
		Node *right;
	public:
		Node(const int value) : value(value), left(NULL), right(NULL){}
		Node *getLeft() const {return left;}
		Node *getRight() const {return right;}
		void setLeft(Node *left){this->left = left;}
		void setRight(Node *right){this->right = right;}
};


Node *rotateTreeRight(Node *oldRoot){
	Node *newNode = oldRoot->getLeft();
	oldRoot->setLeft(newNode->getRight());
	newNode->setRight(oldRoot);
	return newNode;
}

int main(void){
	Node *root = new Node(6);
	Node *N4 = new Node(4);
	Node *N7 = new Node(7);
	Node *N2 = new Node(2);
	Node *N5 = new Node(5);
	Node *N1 = new Node(1);
	Node *N3 = new Node(3);

	root->setLeft(N4);
	root->setRight(N7);

	N4->setLeft(N2);
	N4->setRight(N5);
	
	N2->setLeft(N1);
	N2->setRight(N3);

	rotateTreeRight(root);

	
	return 0;
}
