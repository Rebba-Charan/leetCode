class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans= 0;
        int mul = 1;
        while(n>=8)
        {
            ans+=(8*mul);
            mul++;
            n-=8;
        }
        ans+=(n*mul);
        return ans;
    }
};