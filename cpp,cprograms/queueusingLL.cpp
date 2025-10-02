#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* frontPtr = nullptr;
Node* rearPtr = nullptr;

void enqueue(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!rearPtr) {
        frontPtr = rearPtr = newNode;
    } else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
    cout << value << " enqueued\n";
}

void dequeue() {
    if (!frontPtr) {
        cout << "Queue Underflow\n";
        return;
    }
    Node* temp = frontPtr;
    cout << frontPtr->data << " dequeued\n";
    frontPtr = frontPtr->next;
    if (!frontPtr) rearPtr = nullptr;
    delete temp;
}

void peek() {
    if (!frontPtr) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Front element: " << frontPtr->data << "\n";
}

void display() {
    Node* temp = frontPtr;
    cout << "Queue: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    peek();
    display();
    return 0;
}
