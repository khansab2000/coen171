
#include <cstdlib>
#include <iostream>

template<class T>
class Node {
	T value;
	Node<T> *left;
	Node<T> *right;

public:
	Node(const T &anObject);
	void insert(const T &anObject);
	bool member(const T &anObject) const;
};

template<class T>
Node<T>::Node(const T &anObject){
	value = anObject;
	left = NULL;
	right = NULL;
}
//initializing the node

template <class T>
bool Node<T>::member(const T &anObject) const{
	if (anObject<value){
		if(left == NULL)
			return false;
		else
			return left->member(anObject);
	}
	if (anObject>value){
		if(right == NULL)
			return false;
		else
			return right->member(anObject);
	}
	return true;
}

template <class T>
void Node<T>::insert(const T &anObject){
	if (anObject<value){
		if (left == NULL)
			left = new Node<T>(anObject);
		else
			left->insert(anObject);
	}
	if (anObject>=value){
		if (right == NULL)
			right = new Node<T>(anObject);
		else
			right->insert(anObject);
	}
}

template <class T>
class Tree {
	Node<T> *root;

public:
	Tree(){root = NULL;};
	bool member(const T &anObject) const;
	void insert(const T &anObject);
};

template <class T>
bool Tree<T>::member(const T &anObject) const{
	if (root == NULL)
		return false;
	else
		return root->member(anObject);
}

template <class T>
void Tree<T>::insert(const T &anObject){
	if (root == NULL)
		root = new Node<T>(anObject);
	else
		root->insert(anObject);
}

int main(){
	Tree<int> *t;
	t = new Tree<int>();

	t->insert(15);
	t->insert(10);
	t->insert(20);
	t->insert(5);
	t->insert(30);
	t->insert(25);

	std::cout << t->member(15) << std::endl;
	std::cout << t->member(5) << std::endl;
	std::cout << t->member(25) << std::endl;
	std::cout << t->member(7) << std::endl;
	std::cout << t->member(11) << std::endl;
	std::cout << t->member(44) << std::endl;
	return 0;
}

	








