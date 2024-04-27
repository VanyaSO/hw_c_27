#include "List.h"
#include "../Node/Node.h"
#include <iostream>
using namespace std;

List::List(): _head(nullptr), _tail(nullptr), _size(0U)
{
}

List::List(const List &list)
{
    deleteAll();

    Node* node = list._head;

    while (list._head != nullptr)
    {
        addToHead(node->_data);

        node = node->_next;
    }
}

List::~List()
{
    deleteAll();
}

void List::reverseRecursion(Node* prev, Node* current)
{
    if (current->_next != nullptr)
    {
        reverseRecursion(current, current->_next);
    }
    else
    {
        _head = current;
    }

    current->_next = prev;
}

void List::addToHead(int data)
{
    Node* newNode = new Node(data);

    if (_head == nullptr && _tail == nullptr)
    {
        _head = newNode;
        _tail = newNode;
    }
    else
    {
        Node* temp = _head;
        _head = newNode;
        newNode->_next = temp;
    }
    _size++;
}

void List::addToTail(int data)
{
    Node* newNode = new Node(data);

    if (_head == nullptr && _tail == nullptr)
    {
        _head = newNode;
        _tail = newNode;
    }
    else
    {
        Node* temp = _tail;
        _tail = newNode;
        temp->_next = _tail;
    }
    _size++;
}

void List::deleteFromHead()
{
    if (_head != nullptr)
    {
        Node* node = _head;
        _head = _head->_next;
        delete node;
        _size--;
    }
}

void List::deleteFromTail()
{
    if (_tail != nullptr)
    {
        Node* node = _head;
        for (int i = 1; i <= _size; ++i)
        {
            if (i == _size-1)
            {
                Node* temp = _tail;
                _tail = node;
                _tail->_next = nullptr;
                delete temp;
                _size--;
                return;
            }
            node = node->_next;
        }
    }
}

void List::deleteAll()
{
    while (_head != nullptr)
    {
        deleteFromHead();
    }
}

void List::insertIntoPosition(int data, int position)
{
    if (_head != nullptr && position <= _size && position > 0)
    {
        Node* newNode = new Node(data);
        Node* node = _head;
        Node* prev = nullptr;
        for (int i = 1; node != nullptr; ++i) {
            if (i == position-1)
                prev = node;

            if (i == position)
            {
                prev->_next = newNode;
                newNode->_next = node;
                _size++;
                return;
            }

            node = node->_next;
        }
    }
}

void List::deleteIntoPosition(int position)
{
    if (_head != nullptr && position > 0 && position <= _size)
    {
        Node* node = _head;
        Node* prev;
        Node* temp;
        for (int i = 1; node != nullptr; ++i) {
            if (i == position-1)
                prev = node;

            if (i == position)
            {
                temp = node;
                prev->_next = node->_next;
                delete temp;
                _size--;
                return;
            }

            node = node->_next;
        }
    }
}

int List::getSearchEl(int el) const {
    if (_head != nullptr)
    {
        Node* node = _head;
        for (int i = 1; node != nullptr; ++i) {
            if (node->_data == el)
                return i;

            node = node->_next;
        }
    }
    return NULL;
}

int List::changeEL(int changeEl, int newEl) {
    if (_head != nullptr)
    {
        Node* node = _head;
        int countChangeEl = 0;
        for (int i = 1; node != nullptr; ++i) {
            if (node->_data == changeEl)
            {
                node->_data = newEl;
                countChangeEl++;
            }

            node = node->_next;
        }
        if (countChangeEl > 0)
            return countChangeEl;
    }

    return -1;
}

void List::reverse() {
    if (_head != nullptr) {
        reverseRecursion(nullptr, _head);
    }
}

void List::show() const
{
    Node* node = _head;

    while (node != nullptr)
    {
        cout << node->_data << " ";
        node = node->_next;
    }
    cout << endl;
}
