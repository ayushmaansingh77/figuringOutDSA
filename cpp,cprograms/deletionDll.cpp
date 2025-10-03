// dll_cpp.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *back;
    Node(int d, Node* n=nullptr, Node* b=nullptr) : data(d), next(n), back(b) {}
};

/* create from vector */
Node* convertArr2dll(const vector<int> &arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        Node* temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }
    prev->next = nullptr;
    return head;
}

void print(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << "\n";
}

/* delete head */
Node* deleteHead(Node* head) {
    if (!head) return nullptr;
    if (!head->next) { delete head; return nullptr; }
    Node* old = head;
    head = head->next;
    head->back = nullptr;
    delete old;
    return head;
}

/* delete tail */
Node* deleteTail(Node* head) {
    if (!head) return nullptr;
    if (!head->next) { delete head; return nullptr; }
    Node* tail = head;
    while (tail->next) tail = tail->next;
    Node* prev = tail->back;
    prev->next = nullptr;
    delete tail;
    return head;
}

/* ---------- insertion routines in C++ ---------- */

/* insert at beginning */
Node* insert_at_begin(Node* head, int val) {
    Node* n = new Node(val);
    n->next = head;
    n->back = nullptr;
    if (head) head->back = n;
    return n;
}

/* insert at end */
Node* insert_at_end(Node* head, int val) {
    Node* n = new Node(val);
    n->next = nullptr;
    if (!head) { n->back = nullptr; return n; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    n->back = cur;
    return head;
}

/* insert after first node with target value (if not found, append at end) */
Node* insert_after_value(Node* head, int target, int val) {
    if (!head) return new Node(val);
    Node* cur = head;
    while (cur && cur->data != target) cur = cur->next;
    if (!cur) return insert_at_end(head, val);
    Node* n = new Node(val);
    n->next = cur->next;
    n->back = cur;
    cur->next = n;
    if (n->next) n->next->back = n;
    return head;
}

/* free list */
void freeList(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 34};
    Node* head = convertArr2dll(arr);

    cout << "Initial list:\n"; print(head);

    cout << "Insert 3 at beginning:\n"; head = insert_at_begin(head, 3); print(head);
    cout << "Insert 99 at end:\n"; head = insert_at_end(head, 99); print(head);
    cout << "Insert 42 after 8:\n"; head = insert_after_value(head, 8, 42); print(head);

    cout << "Delete head:\n"; head = deleteHead(head); print(head);
    cout << "Delete tail:\n"; head = deleteTail(head); print(head);

    freeList(head);
    return 0;
}
