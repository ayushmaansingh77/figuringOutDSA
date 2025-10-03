#include<bits/stdc++.h>
using namespace std;
 struct Node {
   int data;
   Node *next;
   Node *back;

   Node(int data1,Node* next1,Node * back1)
{
    data=data1;
    next=next1;
    back=back1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
    back=nullptr;
}
 };

 Node * convertArr2dll(vector <int> &arr)
 { Node* head = new Node(arr[0]);
    head->back = nullptr;        // explicit, though constructor already set it
    Node* prev = head;
     for(int i=1;i<arr.size();i++)
     {
        Node* temp = new Node(arr[i]);
        temp->back = prev;      // set backward link
        prev->next = temp;      // set forward link
        prev = temp;
     }
     prev->next = nullptr;       // terminate the list

     return head;
 }
 void print(Node*head)
 {

    while(head!=NULL)
    {
        cout<<head->data<<"   ,";
        head=head->next;

    }
 }
 int main()
 {
    vector <int> arr={12,5,8,7,34};
    Node *head=convertArr2dll(arr);
    print(head);
 }