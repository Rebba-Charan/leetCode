class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return n;
        int ans = 0;
        while(n>0)
        {
            ans++;
            n/=2;
        }
        return pow(2,ans);
    }
};