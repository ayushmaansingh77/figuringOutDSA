class Solution {
public:
    bool checkValidString(string s) {
        int low=0,high=0;
        for(auto &ch:s)
        {
            if(ch=='(')
            {low++; high++;}
            if(ch==')')
            {low--; high--;}
            if(ch=='*')
            {low--;
            high++;}

            if(high<0)
            {return false;}
            low= max(0,low);
        }

        return low==0;
    }
};