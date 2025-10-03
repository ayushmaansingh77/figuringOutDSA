#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
Node(int data1,Node* next1)
    {data=data1;
        next=next1;

    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
//insertino at the head
Node *insertHead(Node *head,int val){
    Node *temp=new Node(val,head);
    return temp;
}

//to insert at the lat of the linked list
 Node *insertTail(Node *head,int val){
    if(head==nullptr){
    return new Node(val);}
    Node *temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    Node * newNode=new Node(val);
    temp->next=newNode;
    return head;
 }
//insert at kth element
Node *insertK(Node *head,int el,int k)
{
    if(head==NULL){
        if(k==1)
        {
            return new Node(el);
        }
        else{return NULL;}


    }
    if(k==1)
    {
        Node *temp=new Node(el,head);
        return temp;
    }
     int cnt=0;
     Node *temp=head;
     while(temp!=NULL)
     {
        cnt++;

        if(cnt==k-1)
        {
            Node *x=new Node(el);
            x->next=temp->next;
            temp->next=x;
            return head;
        }
        temp=temp->next;
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

    head = insertK(head,100,3);

    printList(head);  // output: 12 3 7 12 15

    freeList(head);
    return 0;
}