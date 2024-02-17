#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <cstddef>
template<class T>
class List {
public:
    List() : _head(nullptr), _tail(nullptr), _size(0) { }
    ~List();

    size_t size();
    Node<T>* get_head();
    Node<T>* get_tail();
    Node<T>* push_back(Node<T>* nodeToPush);
    Node<T>* push_back(T value);
    Node<T>* push_front(Node<T>* nodeToPush);
    Node<T>* push_front(T value);
    Node<T>* push_next(Node<T>* relativeNode, Node<T>* nodeToPush);
    Node<T>* push_prev(Node<T>* relativeNode, Node<T>* nodeToPush);

private:
    Node<T>* _head;
    Node<T>* _tail;
    size_t _size;
};

typedef List<int> ListInt;
typedef List<List<int>*> ListList;

// #include "list.cpp"
#endif // LIST_H