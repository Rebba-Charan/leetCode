class Solution {
    int dp[101];
    int solve(int i,vector<int>& nums)
    {
        if(i>= nums.size()) return 0;
        if(i == (nums.size() - 1)) return nums[i];
        if(dp[i]!=-1) return dp[i];
        int amount1 = nums[i] + solve(i + 2,nums);
        int amount2 = nums[i+1] + solve(i + 3,nums);
        return dp[i] = max(amount1,amount2);
    }
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        if(n == 2) return *max_element(nums.begin(),nums.end());
        return solve(0,nums);
    }
};