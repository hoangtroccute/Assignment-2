#include "StackVector.h"
#include <stdexcept>

bool Stack::empty() const {
    return data.empty();
}

void Stack::push(int val) {
    data.push_back(val);
}

void Stack::pop() {
    if (!empty())
        data.pop_back();
    else
        std::cout << "Stack is empty!\n";
}

int Stack::top() const {
    if (empty()) throw std::runtime_error("Stack is empty");
    return data.back();
}

double Stack::average() const {
    if (empty()) return 0.0;
    double sum = std::accumulate(data.begin(), data.end(), 0);
    return sum / data.size();
}

void Stack::print() const {
    std::cout << "Stack elements: ";
    for (int val : data) std::cout << val << " ";
    std::cout << std::endl;
}
