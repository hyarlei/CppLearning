/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 1
 ***********************************************************/

Item& ForwardList::front() {
    return m_head->next->value;
}

Item& ForwardList::back() {
    Node *current = m_head;
    while(current->next != nullptr) {
        current = current->next;
    }
    return current->value;
}

void ForwardList::push_front(const Item& val) {
    Node *newNode = new Node(val, m_head->next);
    m_head->next = newNode;
    m_size++;
}

void ForwardList::pop_front() {
    Node *temp = m_head->next;
    m_head->next = temp->next;
    delete temp;
    m_size--;
}

void ForwardList::push_back(const Item& val) {
    Node *current = m_head;
    while(current->next != nullptr) {
        current = current->next;
    }
    Node *newNode = new Node(val, nullptr);
    current->next = newNode;
    m_size++;
}

void ForwardList::pop_back() {
    Node *current = m_head;
    while(current->next->next != nullptr) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

/***********************************************************
 * Funcoes adicionais - Parte 2
 ***********************************************************/

void ForwardList::concat(ForwardList& lst) {
    Node *current = m_head;
    while(current->next != nullptr) {
        current = current->next;
    }
    current->next = lst.m_head->next;
    m_size += lst.m_size;
    lst.m_head->next = nullptr;
    lst.m_size = 0;
}

void ForwardList::remove(const Item& val) {
    Node *current = m_head;
    while(current->next != nullptr) {
        if(current->next->value == val) {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            m_size--;
        } else {
            current = current->next;
        }
    }
}

void ForwardList::reverse() {
    Node *current = m_head->next;
    Node *prev = nullptr;
    Node *next = nullptr;
    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    m_head->next = prev;
}

ForwardList* ForwardList::clone() {
    ForwardList *newList = new ForwardList();
    Node *current = m_head->next;
    Node *newCurrent = newList->m_head;
    while(current != nullptr) {
        newCurrent->next = new Node(current->value, nullptr);
        current = current->next;
        newCurrent = newCurrent->next;
    }
    newList->m_size = m_size;
    return newList;
}

void ForwardList::appendVector(const std::vector<Item>& vec) {
    Node *current = m_head;
    while(current->next != nullptr) {
        current = current->next;
    }
    for(int i = 0; i < vec.size(); i++) {
        Node *newNode = new Node(vec[i], nullptr);
        current->next = newNode;
        current = current->next;
    }
    m_size += vec.size();
}

void ForwardList::swap(ForwardList& lst) {
    Node *tempHead = m_head;
    int tempSize = m_size;
    m_head = lst.m_head;
    m_size = lst.m_size;
    lst.m_head = tempHead;
    lst.m_size = tempSize;
}

bool ForwardList::equals(const ForwardList& lst) const {
    if(m_size != lst.m_size) {
        return false;
    }
    Node *current = m_head->next;
    Node *lstCurrent = lst.m_head->next;
    while(current != nullptr) {
        if(current->value != lstCurrent->value) {
            return false;
        }
        current = current->next;
        lstCurrent = lstCurrent->next;
    }
    return true;
}

Item& ForwardList::get(int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::get(int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}