#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>

using std::ostream;

template <class T>
struct Node {
	T info;
	Node<T> * next;
};

template <class T>
class LinkedList {
public:
	LinkedList() { head = nullptr; }
	LinkedList(const LinkedList<T> & rhs) { deepCopy(rhs); }
	LinkedList<T> & operator = (const LinkedList<T> & rhs);
	~LinkedList() { makeEmpty(); }

	void addEl(const T & el);           // O(1) steps
 	bool findEl(const T & el) const;    // O(n) steps
	bool retrieveEl(T & el) const;      // O(n) steps
	bool removeEl(const T & el);        // O(n) steps
	template <class T1>
	friend ostream & operator << (ostream & os, const LinkedList<T1> & myList);
	void makeEmpty();

private:
	Node <T> * head;
	void deepCopy(const LinkedList<T> & rhs);
};

template <class T>
LinkedList<T> & LinkedList<T>::operator = (const LinkedList<T> & rhs) {
	if (this == &rhs) return (*this);
	makeEmpty(); deepCopy(rhs); return (*this);
}

template <class T>
void LinkedList<T>::addEl(const T & el) {	// O(1) steps
	Node<T> * newNode = new Node<T>;
	newNode->info = el; 	// 	(*newNode).info = el;
	newNode->next = head;
	head = newNode;
}

template <class T>
bool LinkedList<T>::findEl(const T & el) const {	// O(n) steps
	Node<T> * curr = head;
	while (curr != nullptr) {
		if (curr->info == el) return true;
		curr = curr->next;
	}
	return false;
}

template <class T>
bool LinkedList<T>::retrieveEl(T & el) const {			// O(n) steps
	Node<T> * curr = head;
	while (curr != nullptr) {
		if (curr->info == el) {
			el = curr->info;
			return true;
		}
		curr = curr->next;
	}
	return false;
}

template <class T>
bool LinkedList<T>::removeEl(const T & el) {        // O(n) steps
	if (head == nullptr) return false;
	Node<T> * prevNode = head;
	if (head->info == el) {
		head = head->next;
		delete prevNode;
		return true;
	}
	// the match is in the second or later node (or) there is no match
	Node<T> * curr = head->next;
	while (curr != nullptr) {
		if (curr->info == el) {
			prevNode->next = curr->next;
			delete curr;
			return true;
		}
		prevNode = curr;
		curr = curr->next;
	}
	return false;
}

template <class T>
void LinkedList<T>::makeEmpty() {
	Node<T> * curr = head;
	while (curr != nullptr) {
		Node<T> * temp = curr;
		curr = curr->next;
		delete temp;
	}
	head = nullptr;
}

template <class T>
void LinkedList<T>::deepCopy(const LinkedList<T> & rhs) {
    if (rhs.head == nullptr) { head = nullptr; return; }
    Node<T> * prevNode = new Node<T>;
    head = prevNode;
    prevNode->info = rhs.head->info;
    Node<T> * rhsNode = rhs.head->next;
    while (rhsNode != nullptr) {
        Node<T> * currNode = new Node<T>;
        prevNode->next = currNode; currNode->info = rhsNode->info;
        rhsNode = rhsNode->next;
        prevNode = currNode;
    }
    prevNode->next = nullptr;
}

template <class T>
ostream & operator << (ostream & os, const LinkedList<T> & myList) {	// O(n) steps
	Node<T> * curr = myList.head;
	while (curr != nullptr) {
		os << curr->info << "->";
		curr = curr->next;
	}
	return os;
}


#endif // LINKEDLIST_H_INCLUDED
