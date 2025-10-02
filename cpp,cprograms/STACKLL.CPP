#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value) {
    Node* newNode = new Node{value, top};
    top = newNode;
    cout << value << " pushed\n";
}

void pop() {
    if (!top) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    cout << top->data << " popped\n";
    top = top->next;
    delete temp;
}

void peek() {
    if (!top) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << top->data << "\n";
}

void display() {
    Node* temp = top;
    cout << "Stack: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    display();
    return 0;
}
