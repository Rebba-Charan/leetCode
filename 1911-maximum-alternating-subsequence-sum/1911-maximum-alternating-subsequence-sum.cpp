class Solution {
public:
    typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
       ll dp[100001][2];
       dp[0][1] = 0;
       dp[0][1] = 0;
       int n = nums.size();
       for(int i = 1;i<n+1;i++)
       {
        dp[i][0] = max(dp[i-1][1]-nums[i-1],dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0]+ nums[i-1],dp[i-1][1]);
       }
       return max(dp[n][0],dp[n][1]);

    }
};