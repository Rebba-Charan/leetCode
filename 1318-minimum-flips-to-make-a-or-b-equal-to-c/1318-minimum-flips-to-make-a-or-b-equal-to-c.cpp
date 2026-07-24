class Solution {
public:
    int minFlips(int a, int b, int c) {
       int ans = 0;
       while(a>0 || b>0 || c>0)
       {
        int a_bit = a%2,b_bit = b%2,c_bit = c%2;
        if(c_bit == 0)
        {
            if(a_bit == 1 && b_bit == 1)
            {
                ans+=2;
            }
            else if(a_bit ==1 || b_bit == 1)
            {
                ans+=1;
            }
        }
        else
        {
            if(a_bit ==0 && b_bit ==0)
            {
                ans+=1;
            }
        }
        a/=2;
        b/=2;
        c/=2;
       } 
       return ans;
    }
};