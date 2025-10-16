#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H

#include <vector>
#include <iostream>
#include <numeric> // for accumulate

class Stack {
private:
    std::vector<int> data;

public:
    bool empty() const;
    void push(int val);
    void pop();
    int top() const;
    double average() const;
    void print() const;
};

#endif
#pragma once
