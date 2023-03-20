#pragma once
#include <stdexcept>
#include <sstream>

using Item = int;

class Node {
	friend class ForwardList;
private:
	Item value;
	Node* next;
public:
	Node(const Item& val, Node* nextPtr) {
		value = val;
		next = nextPtr;
	}
};

class ForwardList
{
private:
	Node* m_head{ nullptr };	// Aponta para o in�cio da lista.
	int m_size{ 0 };			// N�mero de elementos na lista.
public:
	ForwardList();
	bool empty() const;
	int size() const;
	void clear();
	Item& operator[](int index);
	const Item& operator[](int index) const;
	void push_front(Item val);
	void push_back(Item val);
	void insert_at(int index, const Item& val);
	void remove_at(int index);
	~ForwardList();
	ForwardList(int *vet, int n);
	ForwardList(const ForwardList& lst);
	const ForwardList& operator=(const ForwardList& lst);
	bool equals(const ForwardList& lst);
	void concat(const ForwardList& lst);
	void reverse();
	void swap(ForwardList& lst);
	void remove(const Item& val);
	Item& back();
	const Item& back() const;
	void pop_back();
	Item& front();
	const Item& front() const;
	void pop_front();
	std::string str() const;
};

