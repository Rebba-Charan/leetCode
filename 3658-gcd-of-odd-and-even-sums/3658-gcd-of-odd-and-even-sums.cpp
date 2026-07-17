class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0,sumEven = 0;
        int odd,even;
        for(int i = 0;i<n;i++)
        {
            if(i == 0)
            {
                odd = 1;
                even = 2;
            }
            else
            {
            odd+=2;
            even+=2;
            }
            sumOdd+=odd;
            sumEven+=even;
        }
        return gcd(sumOdd,sumEven);
    }
};