class Solution {
public:
int getsumprod(int n)
{
    int num=n;
    int sum=0;
    int prod=1;
    while(num>0)
    {
        int d=num%10;
        sum=sum+d;
        prod*=d;
        num=num/10;

    }
    
    return (sum+prod);
}


    bool checkDivisibility(int n) {
       int div=getsumprod(n);
        if(n%div==0)
        {
            return true;

        }
        else 
        {return false;}
    }
};