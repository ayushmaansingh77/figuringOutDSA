#include <stdio.h>
#define MAX 100
int s[MAX];
int top=-1;
  int isEmpty()
  {
    if(top==-1){
        return 1;
    }
    else 
    return 0;
  }
  int isFull()
  {
    if(top==MAX-1)
    {
        return 1;
    }
    else
    return 0;

  }
  void peek()
  {
    if(isEmpty()){
    printf("stack underflow");}
    else{printf("top element is %d",s[top]);}
  }
     void pop(){
    if (isEmpty())
    {
        printf("stack under flow");
    }
    else
    printf("popped element is: %d::",s[top]);
    printf("\n");
    top-=1;
}
void push(int x)
{
    if(isFull())
    {
        printf("stach over flow");
    }
    else {
        s[++top]=x;
    }
}

void print()
{
    for(int i=0;i<=top;i++)
    {
        printf("%d, ",s[i]);
    }
}
int main()
{
    push(5);
    push(19);
    push(50);
    push(12);
    push(52);
    push(33);
    print();
    pop();
    print();
    peek();
    

}