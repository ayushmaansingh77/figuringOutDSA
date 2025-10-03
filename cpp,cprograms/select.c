#include<stdio.h>
int main()
{
    int n;
    
    printf("enter the size fo the arrray \n");
    scanf("%d",&n);
    int a[n];
    printf("enter the array elements \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }

for(int i=0;i<n-1;i++)
{  
    for(int j=0;j<i;j++)
    {
        if(a[j]>a[j+1])
        {
            int temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        }

        
    }

printf("sorted array\n ");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
}
}
