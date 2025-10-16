#include <iostream>
#include "Single_Linked_List.h"
#include "StackVector.h"

using namespace std;

int main() {
    cout << "===== Question 1: Single Linked List =====\n";
    Single_Linked_List list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.insert(1, 15);

    cout << "Initial list: ";
    list.print_list();

    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;
    cout << "Find 20 -> Index " << list.find(20) << endl;

    list.remove(1);
    cout << "After removing index 1: ";
    list.print_list();

    list.pop_back();
    cout << "After pop_back: ";
    list.print_list();

    cout << "Is empty? " << (list.empty() ? "Yes" : "No") << endl;

    cout << "\n===== Question 2: Stack Using Vector =====\n";
    Stack s;

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.print();

    cout << "Top element: " << s.top() << endl;
    s.pop();
    s.print();

    cout << "Average value: " << s.average() << endl;

    return 0;
}
