#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>

// Non-template version for Visual Studio (int type only)
class Single_Linked_List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    // Constructor / Destructor
    Single_Linked_List();
    ~Single_Linked_List();

    // Core operations
    void push_front(int item);
    void push_back(int item);
    void pop_front();
    void pop_back();

    int front() const;
    int back() const;
    bool empty() const;

    void insert(size_t index, int item);
    bool remove(size_t index);
    size_t find(int item) const;

    void print_list() const;
};

#endif
#pragma once
