#include "list.h"
#include <cstddef>
#include <iostream>

template<class T>
List<T>::~List() {
    Node<T>* current = _head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template<class T>
size_t List<T>::size() 
{
    return _size;
}

template<class T>
Node<T>* List<T>::get_head() 
{
    return _head;
}

template<class T>
Node<T>* List<T>::get_tail() 
{
    return _tail;
}

template<class T>
Node<T>* List<T>::push_back(Node<T>* nodeToPush) 
{
    Node<T>* newNode = new Node<T>(nodeToPush->value);
    if (_head == nullptr)
        {
        _head = newNode;
        _tail = _head;
        }
    else
        {
        _tail->next = newNode;
        newNode->prev = _tail;
        _tail = _tail->next;
        }
    ++_size;
    return newNode;
}

template<class T>
Node<T>* List<T>::push_back(T value)                 // Добавление элемента в конец списка
{
    Node<T>* newNode;
    if (_head == nullptr)
        {
        newNode = new Node<T>(value);
        _head = newNode;
        _tail = _head;
        }
    else
        {
        newNode = new Node<T>(value);
        _tail->next = newNode;
        newNode->prev = _tail;
        _tail = _tail->next;
        }
    ++_size;
    return newNode;
}

template<class T>
Node<T>* List<T>::push_front(Node<T>* nodeToPush)    // Добавление элемента в начало списка
    {
    Node<T>* newNode = new Node<T>(nodeToPush->value);

    newNode->next = _head;
    _head = newNode;
    ++_size;
    return newNode;


}

template<class T>
Node<T>* List<T>::push_front(T value)                // Добавление элемента в начало списка
    {
    Node<T>* newNode;
    if (_head == nullptr)
        {
        newNode = new Node<T>(value);
        _head = newNode;
        _tail = _head;
        }
    else
        {
        newNode = new Node<T>(value);
        newNode->next = _head;
        _head->prev = newNode;
        _head = newNode;
        }
    ++_size;
    return newNode;
    }

template<class T>
Node<T>* List<T>::push_next(Node<T>* relativeNode, Node<T>* nodeToPush)          // Добавление элемента после указанного элемента
    {
    if (relativeNode == _tail)
        {
        return push_back(nodeToPush);
        }

    Node<T>* newNode = new Node<T>(nodeToPush->value);

    Node<T>* next = relativeNode->next;

    newNode->next = next;
    newNode->prev = relativeNode;
    next->prev = newNode;
    relativeNode->next = newNode;

    ++_size;
    return newNode;
    }

template<class T>
Node<T>* List<T>::push_prev(Node<T>* relativeNode, Node<T>* nodeToPush)           // Добавление элемента перед указанным элементом
    {
    if (relativeNode == _head)
        {
        return push_front(nodeToPush);
        }

    Node<T>* newNode = new Node<T>(nodeToPush->value);

    Node<T>* prev = relativeNode->prev;

    newNode->next = relativeNode;
    newNode->prev = prev;

    prev->next = newNode;
    relativeNode->prev = newNode;

    ++_size;
    return newNode;
    }


