#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    }

};
int main()
{
    vector<int> arr={2,4,6,7,8};
    Node* y=new Node(arr[3],nullptr);
    cout<<y->data;
}
