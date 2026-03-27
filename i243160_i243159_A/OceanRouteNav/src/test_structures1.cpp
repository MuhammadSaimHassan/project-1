#include <iostream>
#include <string>
#include "../include/SimpleVector.h"
#include "../include/SimpleList.h"
#include "../include/SimpleQueue.h"

using namespace std;

int main() {
    // -----------------------
    // Testing SimpleVector
    // -----------------------

    cout << "Testing Vector..." << endl;
    SimpleVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    cout << "Vec[1]: " << vec[1] << " (Expected: 20)" << endl;

    
    // -----------------------
    // Testing SimpleList
    // -----------------------
    cout << "Testing List..." << endl;
    SimpleList<string> list;
    list.push_back("Port A");
    list.push_back("Port B");
    
    cout << "List items: ";
    Node<string>* curr = list.begin();
    while(curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    list.remove("Port A");

    cout << "Updated List items: ";
    curr = list.begin();
    while(curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    
    // -----------------------
    // Testing SimpleQueue
    // -----------------------
    cout << "Testing SimpleQueue<int>..." << endl;
    SimpleQueue<int> q;
    cout << "Queue empty initially: " << (q.empty() ? "Yes" : "No") << " (Expected: Yes)" << endl;

    q.push(5);
    q.push(10);
    q.push(15);

    cout << "Queue empty after pushes: " << (q.empty() ? "Yes" : "No") << " (Expected: No)" << endl;
    cout << "Queue front: " << q.front() << " (Expected: 5)" << endl;
    cout << "Queue size (counting): " << q.size() << " (Expected: 3)" << endl;

    cout << "Popping all elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "(Expected: 5 10 15)" << endl;
    cout << "Queue empty after pops: " << (q.empty() ? "Yes" : "No") << " (Expected: Yes)" << endl;

    // Test SimpleQueue with strings
    cout << "Testing SimpleQueue<string>..." << endl;
    SimpleQueue<string> qs;
    qs.push("Alpha");
    qs.push("Beta");
    cout << "Front string: " << qs.front() << " (Expected: Alpha)" << endl;
    qs.pop();
    cout << "Front after pop: " << qs.front() << " (Expected: Beta)" << endl;
    qs.pop();
    cout << "Queue empty (strings): " << (qs.empty() ? "Yes" : "No") << " (Expected: Yes)" << endl;

    return 0;
}