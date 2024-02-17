#pragma once

template<class T>
struct Node {
public:
    T value;
    int i;
    int j;
    Node* next;
    Node* prev;

    Node(T value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};
