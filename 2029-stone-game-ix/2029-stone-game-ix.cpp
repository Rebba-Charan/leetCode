class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n1 = 0,n2 = 0,n0 = 0;
        for(auto a : stones)
        {
            if(a%3 == 0) n0++;
            else if(a%3 ==1) n1++;
            else if(a%3 == 2) n2++;
        }
        if(n0%2 == 0 ) return (n1>=1 && n2>=1 && (n1>=n2 || n2>=n1));
        return  abs(n1-n2)>=3;
    }
};