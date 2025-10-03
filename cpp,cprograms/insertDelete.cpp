#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// delete k-th node (1-based)
Node* deletek(Node* head, int k) {
    if (!head) return head;

    if (k == 1) { // remove head
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while (temp) {
        cnt++;
        if (cnt == k) {
            prev->next = temp->next; // unlink
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* convert2ll(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void freeList(Node* head) {
    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    vector<int> arr = {12, 3, 4, 7, 12, 15};
    Node* head = convert2ll(arr);

    head = deletek(head, 3);

    printList(head);  // output: 12 3 7 12 15

    freeList(head);
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;

//     Node(int data1,Node* next1)
//     {data=data1;
//         next=next1;

//     }
//     Node(int data1){
//         data=data1;
//         next=nullptr;
//     }
// };

// Node * removesHead(Node * head)
// {
//     if(head==nullptr)
//     return head;

//     Node * temp=head;
//     head=head->next;
//     delete temp;
//     return head;


// }

// //***delete the element at the tail */
// Node *deleteTail(Node *head)
// {
//     if(head==nullptr || head->next==nullptr){
//         return nullptr;

//     }
//     Node* temp=head;
//     //temp.next,next!=nullptr

//     while(temp->next->next!=nullptr)
//     {temp=temp->next;

//     }
//     free(temp->next);
//     temp->next=nullptr;
//     return head;
    
// }

// //delete the kth element
// Node *deletek(Node *head,int k){
//     if(head==nullptr)
//     {
//         return head;
//     }
// if(k==1){
//     Node *temp=head;
//     head=head->next;
//     delete temp;
//     return head;
// }

//  int cnt=0;
//  Node *temp=head,*prev=NULL;
//  while(temp!=NULL)
//  {
//     cnt++;
//     if(cnt==k)
//     {
//         prev->next=prev->next->next;
//         delete temp;
//         break;

//     }
//     prev=temp;
//     temp=temp->next;
// }
// return head;
 

// }
//  Node* convert2ll(vector <int> &arr)
// {
//     Node* head=new Node(arr[0]);
//     Node* mover=head;
//     for(int i=1;i<arr.size();i++)
//     {
//         Node* temp=new Node(arr[i]);
//         mover->next=temp;
//         mover=temp;
//     }
//     return head;
// }
// void printList(Node* head) {
//     Node* cur = head;
//     while (cur) {
//         cout << cur->data << " ";
//         cur = cur->next;
//     }
//     cout << "\n";
// }

// int main() {
//     vector<int> arr = {12, 3, 4, 7,12,15};
//     Node* head = convert2ll(arr);
//     head = deletek(head,3);
//     printList(head);      // prints: 3 4 7
//     // free list here...
// }