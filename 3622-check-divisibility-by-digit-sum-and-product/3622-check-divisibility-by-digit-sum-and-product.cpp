class Solution {
public:
    bool checkDivisibility(int n) {
        if(n == 1) return 0;
        int digitsum = 0;
        int digitprod = 1;
        int val = n;
        while(val>0)
        {
            int digitval = val%10;
            digitsum+=digitval;
            digitprod*=digitval;
            val/=10;
        }
        return (n%(digitsum+digitprod) == 0 ? 1 : 0);
    }
};