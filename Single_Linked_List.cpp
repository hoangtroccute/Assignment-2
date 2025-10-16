#include "Single_Linked_List.h"
#include <stdexcept>

Single_Linked_List::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

Single_Linked_List::~Single_Linked_List() {
    while (!empty()) pop_front();
}

void Single_Linked_List::push_front(int item) {
    Node* new_node = new Node(item);
    new_node->next = head;
    head = new_node;
    if (tail == nullptr) tail = head;
    ++num_items;
}

void Single_Linked_List::push_back(int item) {
    Node* new_node = new Node(item);
    if (tail) {
        tail->next = new_node;
    }
    else {
        head = new_node;
    }
    tail = new_node;
    ++num_items;
}

void Single_Linked_List::pop_front() {
    if (empty()) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    --num_items;
    if (head == nullptr) tail = nullptr;
}

void Single_Linked_List::pop_back() {
    if (empty()) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    --num_items;
}

int Single_Linked_List::front() const {
    if (empty()) throw std::runtime_error("List is empty");
    return head->data;
}

int Single_Linked_List::back() const {
    if (empty()) throw std::runtime_error("List is empty");
    return tail->data;
}

bool Single_Linked_List::empty() const {
    return head == nullptr;
}

void Single_Linked_List::insert(size_t index, int item) {
    if (index == 0) {
        push_front(item);
        return;
    }
    if (index >= num_items) {
        push_back(item);
        return;
    }

    Node* prev = head;
    for (size_t i = 0; i < index - 1; ++i)
        prev = prev->next;

    Node* new_node = new Node(item);
    new_node->next = prev->next;
    prev->next = new_node;
    ++num_items;
}

bool Single_Linked_List::remove(size_t index) {
    if (index >= num_items) return false;
    if (index == 0) {
        pop_front();
        return true;
    }

    Node* prev = head;
    for (size_t i = 0; i < index - 1; ++i)
        prev = prev->next;

    Node* temp = prev->next;
    prev->next = temp->next;
    if (temp == tail) tail = prev;
    delete temp;
    --num_items;
    return true;
}

size_t Single_Linked_List::find(int item) const {
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == item) return index;
        current = current->next;
        ++index;
    }
    return num_items;
}

void Single_Linked_List::print_list() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL\n";
}
