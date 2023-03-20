#include "ForwardList.hpp"

ForwardList::ForwardList()
{
	m_head = nullptr;
	m_size = 0;
}

bool ForwardList::empty() const
{
	return m_size == 0;
}

int ForwardList::size() const
{
	return m_size;
}

void ForwardList::clear()
{
	Node* current = m_head;
	while (current) {
		Node* temp = current;
		current = temp->next;
		delete temp;
	}
	m_head = nullptr;
	m_size = 0;
}

Item& ForwardList::operator[](int index)
{
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("fail: index out of range\n");
	}

	Node* current = m_head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->value;
}

const Item& ForwardList::operator[](int index) const
{
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("fail: index out of range\n");
	}

	Node* current = m_head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->value;
}

void ForwardList::push_front(Item val)
{
	Node* newNode = new Node(val, m_head);
	m_head = newNode;
	m_size++;
}

void ForwardList::push_back(Item val)
{
	Node* newNode = new Node(val, nullptr);

	if (m_size == 0) {
		m_head = newNode;
		m_size++;
	}
	else {
		Node* current = m_head;
		while (current->next) {
			current = current->next;
		}
		current->next = newNode;
		m_size++;
	}
}

void ForwardList::insert_at(int index, const Item& val)
{
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("fail: index out of range\n");
	}

	if (index == 0) {
		push_front(val);
		return;
	}

	Node* current = m_head;
	
	for (int i = 0; i < index - 1; i++) {
		current = current->next;
	}
	
	Node* newNode = new Node(val, current->next);
	current->next = newNode;
	m_size++;
}

void ForwardList::remove_at(int index)
{
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("fail: index out of range\n");
	}

	if (index == 0) {
		m_head = m_head->next;
		m_size--;
		return;
	}

	Node* current = m_head;
	
	for (int i = 0; i < index - 1; i++) {
		current = current->next;
	}

	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
	m_size--;
}

ForwardList::~ForwardList()
{
	Node* current = m_head;
	while (current) {
		Node* temp = current;
		current = current->next;
		delete temp;
	}
}

//################################################//

ForwardList::ForwardList(int* vet, int n)
{
	m_head = nullptr;
	m_size = 0;

	for (int i = 0; i < n; i++) {
		push_back(vet[i]);
	}
}

ForwardList::ForwardList(const ForwardList& lst)
{
	Node* source = lst.m_head;
	if (source == nullptr) {
		m_head = nullptr;
		m_size = 0;
		return;
	}

	m_head = new Node(source->value, nullptr);
	Node* target = m_head;
	source = source->next;
	m_size++;

	while (source) {
		target->next = new Node(source->value, nullptr);
		target = target->next;
		source = source->next;
		m_size++;
	}
}

const ForwardList& ForwardList::operator=(const ForwardList& lst)
{
	if (this != &lst) {
		clear();
		for (Node* current = lst.m_head; current; current = current->next) {
			push_back(current->value);
		}
	}
	return *this;
}

bool ForwardList::equals(const ForwardList& lst)
{
	if (m_size != lst.m_size) {
		return false;
	}

	Node* current = m_head;
	Node* lst_current = lst.m_head;

	while (current && lst_current) {
		if (current->value != lst_current->value) {
			return false;
		}
		current = current->next;
		lst_current = lst_current->next;
	}

	return true;
}

void ForwardList::concat(const ForwardList& lst)
{
	Node* current = lst.m_head;

	while (current) {
		push_back(current->value);
		current = current->next;
	}
}

void ForwardList::reverse()
{
	ForwardList reversed;
	Node* current = m_head;

	while (current) {
		reversed.push_front(current->value);
		current = current->next;
	}

	m_head = reversed.m_head;
	m_size = reversed.m_size;
}

void ForwardList::swap(ForwardList& lst)
{
	std::swap(m_head, lst.m_head);
	std::swap(m_size, lst.m_size);
}

void ForwardList::remove(const Item& val) 
{
	Node* current = m_head;
	int index = 0;

	while (current) {
		if (current->value == val) {
			remove_at(index);
			current = m_head;
			index = 0;
		}
		else {
			current = current->next;
			index++;
		}
	}
}

Item& ForwardList::back()
{
	return (*this)[m_size - 1];
}

const Item& ForwardList::back() const
{
	return (*this)[m_size - 1];
}

void ForwardList::pop_back()
{
	remove_at(m_size - 1);
}

Item& ForwardList::front()
{
	return m_head->value;
}

const Item& ForwardList::front() const
{
	return m_head->value;
}

void ForwardList::pop_front()
{
	remove_at(0);
}

std::string ForwardList::str()const
{
	std::stringstream ss;
	Node* current = m_head;
	ss << "[";
	while (current) {
		ss << current->value;
		if (current->next)
			ss << ", ";
		current = current->next;
	}
	ss << "]";
	return ss.str();
}